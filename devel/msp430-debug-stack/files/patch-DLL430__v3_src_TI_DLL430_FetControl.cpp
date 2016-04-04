--- DLL430_v3/src/TI/DLL430/FetControl.cpp.orig	2016-03-12 13:23:34 UTC
+++ DLL430_v3/src/TI/DLL430/FetControl.cpp
@@ -214,7 +214,7 @@ bool FetControl::resetCommunication()
 	data.push_back(0x00);
 	this->sendData(data);		// reset connection
 
-	std::this_thread::sleep_for(std::chrono::milliseconds(100));
+	std::this_thread::sleep_for(std::chrono::milliseconds(300));
 
 	HalExecElement* el = new HalExecElement(ID_Zero);
 	el->appendInputData8(STREAM_CORE_ZERO_VERSION);
