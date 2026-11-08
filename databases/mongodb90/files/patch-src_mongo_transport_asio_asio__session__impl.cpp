--- src/mongo/transport/asio/asio_session_impl.cpp.orig	2026-09-29 00:00:00 UTC
+++ src/mongo/transport/asio/asio_session_impl.cpp
@@ -270,7 +270,7 @@ CommonAsioSession::CommonAsioSession(GenericSocket soc
 #endif
 }
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 StatusWith<gid_t> getPeerGid(AsioSession::GenericSocket::native_handle_type handle) {
     [[maybe_unused]] uid_t remoteUid;
     gid_t remoteGid;
