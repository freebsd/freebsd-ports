Socket fixes for FreeBSD:
- ENONET is Linux-only (series 0005).
- Set SO_REUSEPORT along with SO_REUSEADDR on UDP sockets, so several
  sockets can share a port as on Linux (series 0018).
FreeBSD-specific, not submitted upstream yet.
--- runtime/bin/socket_linux.cc.orig	2026-09-29 08:00:52 UTC
+++ runtime/bin/socket_linux.cc
@@ -132,6 +132,12 @@ intptr_t Socket::CreateBindDatagram(const RawAddr& add
     int optval = 1;
     VOID_NO_RETRY_EXPECTED(
         setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)));
+#if defined(__FreeBSD__)
+    // On Linux, SO_REUSEADDR lets several UDP sockets bind the same address
+    // and port. On FreeBSD that needs SO_REUSEPORT as well.
+    VOID_NO_RETRY_EXPECTED(
+        setsockopt(fd, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval)));
+#endif
   }
 
   if (reusePort) {
@@ -241,7 +247,10 @@ static bool IsTemporaryAcceptError(int error) {
   // On Linux a number of protocol errors should be treated as EAGAIN.
   // These are the ones for TCP/IP.
   return (error == EAGAIN) || (error == ENETDOWN) || (error == EPROTO) ||
-         (error == ENOPROTOOPT) || (error == EHOSTDOWN) || (error == ENONET) ||
+         (error == ENOPROTOOPT) || (error == EHOSTDOWN) ||
+#if defined(ENONET)  // Not defined on FreeBSD.
+         (error == ENONET) ||
+#endif
          (error == EHOSTUNREACH) || (error == EOPNOTSUPP) ||
          (error == ENETUNREACH);
 }
