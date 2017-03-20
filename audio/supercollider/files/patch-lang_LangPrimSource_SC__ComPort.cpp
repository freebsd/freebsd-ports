--- lang/LangPrimSource/SC_ComPort.cpp.orig	2017-03-20 15:18:39 UTC
+++ lang/LangPrimSource/SC_ComPort.cpp
@@ -44,7 +44,7 @@ void ProcessOSCPacket(OSC_Packet *inPacket, int inPort
 
 //////////////////////////////////////////////////////////////////////////////////////////////////////////
 
-thread gAsioThread;
+std::thread gAsioThread;
 boost::asio::io_service ioService;
 
 
@@ -56,7 +56,7 @@ static void asioFunction()
 
 void startAsioThread()
 {
-	thread asioThread (&asioFunction);
+	std::thread asioThread (&asioFunction);
 	gAsioThread = std::move(asioThread);
 }
 
