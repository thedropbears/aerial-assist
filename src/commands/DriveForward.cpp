#include "DriveForward.h"
#include "../Robotmap.h"

DriveForward::DriveForward():CommandBase("DriveForward"){
	Requires(chassis);
	SetTimeout(2.0);
}

void DriveForward::Initialize(){	
	chassis->drive(1, 0, 0, 1, false);
}

void DriveForward::Execute(){
    
}

bool DriveForward::IsFinished(){
	return IsTimedOut() || beaglebone->goalRange != 99.0;
}

void DriveForward::End(){
	chassis->drive (0,0,0,0);
}

void DriveForward::Interrupted(){
	End();
}	