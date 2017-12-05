--- DLL430_v3/src/TI/DLL430/UpdateManagerMSP_FET430.cpp.orig	2017-12-05 18:38:46.041601000 +0300
+++ DLL430_v3/src/TI/DLL430/UpdateManagerMSP_FET430.cpp	2017-12-05 18:41:45.548342000 +0300
@@ -212,7 +212,7 @@ bool UpdateManagerMSP_FET430::firmWareUp
 		control->sendData(data_55);
 		control->clearResponse();
 
-		this_thread::sleep_for(chrono::seconds(8));
+		this_thread::sleep_for(std::chrono::seconds(8));
 	}
 
 	MemoryContent firmware;
@@ -282,7 +282,7 @@ bool UpdateManagerMSP_FET430::firmWareUp
 	const bool initFailed = !this->fetHandle->send(initCmd);
 
 	// give the firmware time to execute initialisation
-	this_thread::sleep_for(chrono::seconds(1));
+	this_thread::sleep_for(std::chrono::seconds(1));
 
 	//Only an error if no user specified file is used (ie. init will fail for a downgrade)
 	if (initFailed && !fname)
@@ -300,7 +300,7 @@ bool UpdateManagerMSP_FET430::firmWareUp
 		cmd.elements.emplace_back(el);
 
 		fetHandle->send(cmd);
-		this_thread::sleep_for(chrono::seconds(2));
+		this_thread::sleep_for(std::chrono::seconds(2));
 
 		if (callback)
 			callback(BL_UPDATE_DONE, 0, 0);
