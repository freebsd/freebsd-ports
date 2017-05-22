--- Source/RakPeer.cpp.orig	2017-05-14 20:20:15.087088000 +0000
+++ Source/RakPeer.cpp	2017-05-14 20:26:50.670623000 +0000
@@ -154,7 +154,7 @@
 // Should be different than any message that could result from messages from the reliability layer
 #pragma warning(disable:4309) // 'initializing' : truncation of constant value
 // Make sure highest bit is 0, so isValid in DatagramHeaderFormat is false
-static const char OFFLINE_MESSAGE_DATA_ID[16]={0x00,0xFF,0xFF,0x00,0xFE,0xFE,0xFE,0xFE,0xFD,0xFD,0xFD,0xFD,0x12,0x34,0x56,0x78};
+static const unsigned char OFFLINE_MESSAGE_DATA_ID[16]={0x00,0xFF,0xFF,0x00,0xFE,0xFE,0xFE,0xFE,0xFD,0xFD,0xFD,0xFD,0x12,0x34,0x56,0x78};
 
 //#define _DO_PRINTF
 
