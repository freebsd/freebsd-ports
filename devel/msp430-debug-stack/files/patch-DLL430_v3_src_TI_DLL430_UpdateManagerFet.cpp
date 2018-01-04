--- DLL430_v3/src/TI/DLL430/UpdateManagerFet.cpp.orig	2017-12-05 18:47:14.471473000 +0300
+++ DLL430_v3/src/TI/DLL430/UpdateManagerFet.cpp	2017-12-05 18:47:14.610002000 +0300
@@ -128,7 +128,7 @@ bool UpdateManagerFet::updateCore(Memory
 			intCallback(BL_DATA_BLOCK_PROGRAMMED, (uint32_t)( 100-(requiredCoreUpdates)*requiredCoreUpdates), 0);
 		}
 
-		this_thread::sleep_for(chrono::seconds(4));
+		this_thread::sleep_for(std::chrono::seconds(4));
 
 		fetHandle->shutdown();
 
@@ -141,7 +141,7 @@ bool UpdateManagerFet::updateCore(Memory
 		uint32_t countedHidDevices = 0, timeout = 50;
 		do
 		{
-			this_thread::sleep_for(chrono::seconds(1));
+			this_thread::sleep_for(std::chrono::seconds(1));
 			countedHidDevices = HidUpdateManager::countHidDevices(currentPid);
 
 			if (intCallback)
@@ -635,7 +635,7 @@ bool UpdateManagerFet::updateFpga()
 	// Start the FPGA update
 	this->upInit(3);
 
-	this_thread::sleep_for(chrono::seconds(1));
+	this_thread::sleep_for(std::chrono::seconds(1));
 
 	// Restore the normal HAL module
 	if (returnValue && !updateHal())
@@ -956,7 +956,7 @@ bool UpdateManagerFet::firmWareUpdate(co
 
 		UpdateLog.append("\n---------------------Firmware upate end--------------------------\n");
 
-		ofstream(logfile.c_str(), ios::app | ios::out) << UpdateLog;
+		std::ofstream(logfile.c_str(), ios::app | ios::out) << UpdateLog;
 #endif
 	}
 	return returnValue;
@@ -1063,7 +1063,7 @@ bool UpdateManagerFet::updateFirmware(co
 	this->upInit(0);
 
 	// give the firmware time to execute initialisation
-	this_thread::sleep_for(chrono::seconds(1));
+	this_thread::sleep_for(std::chrono::seconds(1));
 	return true;
 }
 
