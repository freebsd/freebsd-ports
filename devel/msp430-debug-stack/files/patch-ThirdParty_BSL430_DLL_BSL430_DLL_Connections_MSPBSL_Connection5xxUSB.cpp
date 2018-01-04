--- ThirdParty/BSL430_DLL/BSL430_DLL/Connections/MSPBSL_Connection5xxUSB.cpp.orig	2017-12-05 18:38:46.035629000 +0300
+++ ThirdParty/BSL430_DLL/BSL430_DLL/Connections/MSPBSL_Connection5xxUSB.cpp	2017-12-05 18:39:43.517163000 +0300
@@ -70,7 +70,7 @@ void MSPBSL_Connection5xxUSB:: closeBslc
 {
 	uint8_t usbDisconnct = USB_DISCONNECT_COMMAND;
 	this->thePacketHandler->TX_Packet(&usbDisconnct,1);
-	this_thread::sleep_for(chrono::seconds(5));
+	this_thread::sleep_for(std::chrono::seconds(5));
 }
 
 /***************************************************************************//**
@@ -134,7 +134,7 @@ uint16_t MSPBSL_Connection5xxUSB::loadRA
 	{
 		return retValue;
 	}
-	this_thread::sleep_for(chrono::seconds(1));
+	this_thread::sleep_for(std::chrono::seconds(1));
 
 	return ACK;
 }
