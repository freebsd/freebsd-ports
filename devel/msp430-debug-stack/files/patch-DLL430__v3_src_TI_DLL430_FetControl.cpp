--- DLL430_v3/src/TI/DLL430/FetControl.cpp.orig	2017-12-05 18:47:14.471975000 +0300
+++ DLL430_v3/src/TI/DLL430/FetControl.cpp	2017-12-05 18:47:14.610359000 +0300
@@ -222,7 +222,7 @@ bool FetControl::resetCommunication()
 	data.push_back(0x00);
 	this->sendData(data);		// reset connection
 
-	std::this_thread::sleep_for(std::chrono::milliseconds(100));
+	std::this_thread::sleep_for(std::chrono::milliseconds(300));
 
 	HalExecElement* el = new HalExecElement(ID_Zero);
 	el->appendInputData8(STREAM_CORE_ZERO_VERSION);
