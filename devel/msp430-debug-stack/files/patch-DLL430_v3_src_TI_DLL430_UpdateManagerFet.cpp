--- DLL430_v3/src/TI/DLL430/UpdateManagerFet.cpp.orig	2018-03-26 17:23:13.431436000 +0300
+++ DLL430_v3/src/TI/DLL430/UpdateManagerFet.cpp	2018-03-26 17:25:33.815661000 +0300
@@ -68,6 +68,7 @@
 
 #include "../../../../Bios/include/MSP_FetDcdc.h"
 #include "../../../../Bios/include/MSP_FetHal.h"
+#include "../../../../Bios/include/MSP_FetFpgaHal.h"
 #include "../../../../Bios/include/MSP_FetHil.h"
 #include "../../../../Bios/include/MSP_FetCore.h"
 #include "../../../../Bios/include/MSP_FetComChannel.h"
@@ -131,7 +132,7 @@
 			intCallback(BL_DATA_BLOCK_PROGRAMMED, (uint32_t)(100 - (requiredCoreUpdates)*percentCore), 0);
 		}
 
-		this_thread::sleep_for(chrono::seconds(4));
+		this_thread::sleep_for(std::chrono::seconds(4));
 
 		fetHandle->shutdown();
 
@@ -144,7 +145,7 @@
 		uint32_t countedHidDevices = 0, timeout = 50;
 		do
 		{
-			this_thread::sleep_for(chrono::seconds(1));
+			this_thread::sleep_for(std::chrono::seconds(1));
 			countedHidDevices = HidUpdateManager::countHidDevices(currentPid);
 
 			if (intCallback)
@@ -648,7 +649,7 @@
 	// Start the FPGA update
 	this->upInit(3);
 
-	this_thread::sleep_for(chrono::seconds(1));
+	this_thread::sleep_for(std::chrono::seconds(1));
 
 	// Restore the normal HAL module
 	if (returnValue && !updateHal())
@@ -839,7 +840,7 @@
 #endif
 			UpdateLog.append("\n---------------------Firmware upate end--------------------------\n");
 
-			ofstream(logfile.c_str(), ios::app | ios::out) << UpdateLog;
+			std::ofstream(logfile.c_str(), ios::app | ios::out) << UpdateLog;
 		}
 
 		return retval;
@@ -1020,7 +1021,7 @@
 #endif
 		UpdateLog.append("\n---------------------Firmware upate end--------------------------\n");
 
-		ofstream(logfile.c_str(), ios::app | ios::out) << UpdateLog;
+		std::ofstream(logfile.c_str(), ios::app | ios::out) << UpdateLog;
 	}
 	return returnValue;
 }
@@ -1134,7 +1135,7 @@
 	this->upInit(0);
 
 	// give the firmware time to execute initialisation
-	this_thread::sleep_for(chrono::seconds(1));
+	this_thread::sleep_for(std::chrono::seconds(1));
 	return true;
 }
 
