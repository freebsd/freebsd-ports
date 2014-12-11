--- ./plugins/collab/backends/tcp/xp/Session.h.orig	2014-12-05 21:51:55.334456277 +0100
+++ ./plugins/collab/backends/tcp/xp/Session.h	2014-12-05 21:51:31.075459132 +0100
@@ -31,7 +31,7 @@
 
 class TCPAccountHandler;
 
-class Session : public Synchronizer, public boost::noncopyable, public boost::enable_shared_from_this<Session>
+class Session : public Synchronizer, public asio::noncopyable, public boost::enable_shared_from_this<Session>
 {
 public:
 	Session(asio::io_service& io_service, boost::function<void (boost::shared_ptr<Session>)> ef)
