--- DLL430_v3/src/TI/DLL430/UpdateManagerMSP_FET430.cpp.orig	2018-03-26 17:14:12.210044000 +0300
+++ DLL430_v3/src/TI/DLL430/UpdateManagerMSP_FET430.cpp	2018-03-26 17:15:34.167641000 +0300
@@ -226,7 +226,7 @@
 
 		for (int i = 0; i < 8; ++i)
 		{
-			this_thread::sleep_for(chrono::seconds(1));
+			this_thread::sleep_for(std::chrono::seconds(1));
 			if (callback)
 			{
 				--requiredUpdates;
@@ -313,7 +313,7 @@
 	const bool initFailed = !this->fetHandle->send(initCmd);
 
 	// give the firmware time to execute initialisation
-	this_thread::sleep_for(chrono::seconds(1));
+	this_thread::sleep_for(std::chrono::seconds(1));
 	if (callback)
 	{
 		--requiredUpdates;
@@ -338,7 +338,7 @@
 		fetHandle->send(cmd);
 		for (int i = 0; i < 2; ++i)
 		{
-			this_thread::sleep_for(chrono::seconds(1));
+			this_thread::sleep_for(std::chrono::seconds(1));
 			if (callback)
 			{
 				--requiredUpdates;
