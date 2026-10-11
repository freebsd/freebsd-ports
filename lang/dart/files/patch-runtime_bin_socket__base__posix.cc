Treat any nonzero boolean socket option value as enabled (series 0002).
FreeBSD and macOS return the option's flag bit, not 1, so
broadcastEnabled and similar read back as false.
Upstream: submitted as dart-lang/sdk#64551 (fixes #50171).
--- runtime/bin/socket_base_posix.cc.orig	2026-09-29 08:00:52 UTC
+++ runtime/bin/socket_base_posix.cc
@@ -423,7 +423,7 @@ bool SocketBase::GetNoDelay(intptr_t fd, bool* enabled
   int err = NO_RETRY_EXPECTED(getsockopt(fd, IPPROTO_TCP, TCP_NODELAY,
                                          reinterpret_cast<void*>(&on), &len));
   if (err == 0) {
-    *enabled = (on == 1);
+    *enabled = (on != 0);
   }
   return (err == 0);
 }
@@ -445,7 +445,7 @@ bool SocketBase::GetMulticastLoop(intptr_t fd,
                                                      : IPV6_MULTICAST_LOOP;
   if (NO_RETRY_EXPECTED(getsockopt(fd, level, optname,
                                    reinterpret_cast<char*>(&on), &len)) == 0) {
-    *enabled = (on == 1);
+    *enabled = (on != 0);
     return true;
   }
   return false;
@@ -480,7 +480,7 @@ bool SocketBase::GetBroadcast(intptr_t fd, bool* enabl
   int err = NO_RETRY_EXPECTED(getsockopt(fd, SOL_SOCKET, SO_BROADCAST,
                                          reinterpret_cast<char*>(&on), &len));
   if (err == 0) {
-    *enabled = (on == 1);
+    *enabled = (on != 0);
   }
   return (err == 0);
 }
