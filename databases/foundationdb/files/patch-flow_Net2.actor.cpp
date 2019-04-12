--- flow/Net2.actor.cpp.orig	2019-04-09 00:11:05 UTC
+++ flow/Net2.actor.cpp
@@ -62,7 +62,7 @@ const uint64_t minValidProtocolVersion       = 0x0FDB0
 // This assert is intended to help prevent incrementing the leftmost digits accidentally. It will probably need to change when we reach version 10.
 static_assert(currentProtocolVersion < 0x0FDB00B100000000LL, "Unexpected protocol version");
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <execinfo.h>
 
 volatile double net2liveness = 0;
@@ -437,6 +437,12 @@ class Connection : public IConnection, ReferenceCounte
 	}
 };
 
+#if BOOST_VERSION >= 107000
+#define GET_IO_SERVICE(s) ((boost::asio::io_context&)(s).get_executor().context())
+#else
+#define GET_IO_SERVICE(s) ((s).get_io_service())
+#endif
+
 class Listener : public IListener, ReferenceCounted<Listener> {
 	NetworkAddress listenAddress;
 	tcp::acceptor acceptor;
@@ -459,7 +465,7 @@ class Listener : public IListener, ReferenceCounted<Li
 
 private:
 	ACTOR static Future<Reference<IConnection>> doAccept( Listener* self ) {
-		state Reference<Connection> conn( new Connection( self->acceptor.get_io_service() ) );
+		state Reference<Connection> conn( new Connection( GET_IO_SERVICE(self->acceptor) ) );
 		state tcp::acceptor::endpoint_type peer_endpoint;
 		try {
 			BindPromise p("N2_AcceptError", UID());
