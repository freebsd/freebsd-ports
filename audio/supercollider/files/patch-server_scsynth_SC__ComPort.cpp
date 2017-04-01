--- server/scsynth/SC_ComPort.cpp.orig	2017-03-20 15:18:39 UTC
+++ server/scsynth/SC_ComPort.cpp
@@ -147,7 +147,7 @@ static bool UnrollOSCPacket(World *inWorld, int inSize
 
 /////////////////////////////////////////////////////////////////////////////////////////////////////////
 
-thread gAsioThread;
+std::thread gAsioThread;
 boost::asio::io_service ioService;
 
 const int kTextBufSize = 65536;
@@ -205,7 +205,7 @@ class SC_UdpInPort
 	boost::asio::ip::udp::endpoint remoteEndpoint;
 
 #ifdef USE_RENDEZVOUS
-	thread mRendezvousThread;
+	std::thread mRendezvousThread;
 #endif
 
 	void handleReceivedUDP(const boost::system::error_code& error,
@@ -264,7 +264,7 @@ class SC_UdpInPort
 
 #ifdef USE_RENDEZVOUS
 		if (world->mRendezvous) {
-			thread thread( boost::bind( PublishPortToRendezvous, kSCRendezvous_UDP, sc_htons(mPortNum) ) );
+			std::thread thread( boost::bind( PublishPortToRendezvous, kSCRendezvous_UDP, sc_htons(mPortNum) ) );
 			mRendezvousThread = std::move(thread);
 		}
 #endif
@@ -394,7 +394,7 @@ class SC_TcpInPort
 	boost::asio::ip::tcp::acceptor acceptor;
 
 #ifdef USE_RENDEZVOUS
-	thread mRendezvousThread;
+	std::thread mRendezvousThread;
 #endif
 
 	std::atomic<int> mAvailableConnections;
@@ -410,7 +410,7 @@ class SC_TcpInPort
 
 #ifdef USE_RENDEZVOUS
 		if (world->mRendezvous) {
-			thread thread( boost::bind( PublishPortToRendezvous, kSCRendezvous_TCP, sc_htons(inPortNum) ) );
+			std::thread thread( boost::bind( PublishPortToRendezvous, kSCRendezvous_TCP, sc_htons(inPortNum) ) );
 			mRendezvousThread = std::move(thread);
 		}
 #endif
@@ -471,7 +471,7 @@ static void asioFunction()
 
 void startAsioThread()
 {
-	thread asioThread (&asioFunction);
+	std::thread asioThread (&asioFunction);
 	gAsioThread = std::move(asioThread);
 }
 
