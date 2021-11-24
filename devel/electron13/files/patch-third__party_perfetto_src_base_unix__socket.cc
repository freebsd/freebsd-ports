--- third_party/perfetto/src/base/unix_socket.cc.orig	2021-07-15 19:15:50 UTC
+++ third_party/perfetto/src/base/unix_socket.cc
@@ -41,7 +41,7 @@
 #include <unistd.h>
 #endif
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) || PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 #include <sys/ucred.h>
 #endif
 
@@ -761,7 +761,8 @@ void UnixSocket::ReadPeerCredentialsPosix() {
   PERFETTO_CHECK(res == 0);
   peer_uid_ = user_cred.uid;
   peer_pid_ = user_cred.pid;
-#elif PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) || \
+      PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   struct xucred user_cred;
   socklen_t len = sizeof(user_cred);
   int res = getsockopt(sock_raw_.fd(), 0, LOCAL_PEERCRED, &user_cred, &len);
