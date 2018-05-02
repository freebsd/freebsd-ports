--- flow/Net2.actor.cpp.orig	2018-04-19 02:55:50 UTC
+++ flow/Net2.actor.cpp
@@ -56,7 +56,7 @@ uint64_t compatibleProtocolVersionMask =
 uint64_t minValidProtocolVersion       = 0x0FDB00A200060001LL;
 
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <execinfo.h>
 
 volatile double net2liveness = 0;
@@ -403,8 +403,7 @@ private:
 
 	void init() {
 		// Socket settings that have to be set after connect or accept succeeds
-		boost::asio::socket_base::non_blocking_io nbio(true);
-		socket.io_control(nbio);
+		socket.non_blocking(true);
 		socket.set_option(boost::asio::ip::tcp::no_delay(true));
 	}
 
