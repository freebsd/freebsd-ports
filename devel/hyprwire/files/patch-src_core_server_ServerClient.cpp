--- src/core/server/ServerClient.cpp.orig	2026-02-04 11:08:13 UTC
+++ src/core/server/ServerClient.cpp
@@ -13,6 +13,11 @@
 #include <sys/socket.h>
 #include <sys/types.h>
 
+#if defined(__FreeBSD__)
+#include <sys/ucred.h>
+#include <sys/un.h>
+#endif
+
 using namespace Hyprwire;
 
 CServerClient::CServerClient(int fd) : m_fd(fd) {
@@ -31,19 +36,29 @@ void CServerClient::dispatchFirstPoll() {
 
     // get peer's pid
 
-#if defined(__OpenBSD__)
+#if defined(__FreeBSD__)
+    struct xucred cred;
+#elif defined(__OpenBSD__)
     struct sockpeercred cred;
 #else
     ucred cred;
 #endif
     socklen_t len = sizeof(cred);
 
+#if defined(__FreeBSD__)
+    if (getsockopt(m_fd.get(), SOL_SOCKET, LOCAL_PEERCRED, &cred, &len) == -1) {
+#else
     if (getsockopt(m_fd.get(), SOL_SOCKET, SO_PEERCRED, &cred, &len) == -1) {
+#endif
         TRACE(Debug::log(TRACE, "dispatchFirstPoll: failed to get pid"));
         return;
     }
 
+#if defined(__FreeBSD__)
+    m_pid = cred.cr_pid;
+#else
     m_pid = cred.pid;
+#endif
 }
 
 void CServerClient::sendMessage(const IMessage& message) {
