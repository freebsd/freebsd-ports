--- third_party/perfetto/src/base/unix_socket.cc.orig	2025-06-30 07:04:30 UTC
+++ third_party/perfetto/src/base/unix_socket.cc
@@ -45,7 +45,7 @@
 #include <unistd.h>
 #endif
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) || defined(__FreeBSD__)
 #include <sys/ucred.h>
 #endif
 
@@ -1031,9 +1031,13 @@ void UnixSocket::ReadPeerCredentialsPosix() {
   int res = getpeereid(fd, &peer_uid_, nullptr);
   PERFETTO_CHECK(res == 0);
   // There is no pid when obtaining peer credentials for QNX
-#elif PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+#elif !defined(__FreeBSD__) && PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
+  struct sockpeercred user_cred;
+#else
   struct ucred user_cred;
+#endif
   socklen_t len = sizeof(user_cred);
   int fd = sock_raw_.fd();
   int res = getsockopt(fd, SOL_SOCKET, SO_PEERCRED, &user_cred, &len);
