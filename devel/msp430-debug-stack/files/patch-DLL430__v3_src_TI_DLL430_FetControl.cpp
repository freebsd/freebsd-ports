--- DLL430_v3/src/TI/DLL430/FetControl.cpp.orig	2020-12-05 20:54:24 UTC
+++ DLL430_v3/src/TI/DLL430/FetControl.cpp
@@ -225,7 +225,7 @@ bool FetControl::resetCommunication()
 	data.push_back(0x00);
 	this->sendData(data);		// reset connection
 
-	std::this_thread::sleep_for(std::chrono::milliseconds(100));
+	std::this_thread::sleep_for(std::chrono::milliseconds(500));
 
 	HalExecElement* el = new HalExecElement(ID_Zero);
 	el->appendInputData8(STREAM_CORE_ZERO_VERSION);
