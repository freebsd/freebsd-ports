Socket fixes for FreeBSD:
- Use the large-file names from platform/largefile.h (series 0006).
- Join multicast groups with IP_ADD_MEMBERSHIP/ip_mreqn and
  IPV6_JOIN_GROUP: FreeBSD rejects interface index 0 with
  MCAST_JOIN_GROUP (series 0018).
FreeBSD-specific, not submitted upstream yet.
--- runtime/bin/socket_base_linux.cc.orig	2026-09-29 08:00:52 UTC
+++ runtime/bin/socket_base_linux.cc
@@ -21,6 +21,7 @@
 #include "bin/file.h"
 #include "bin/socket_base_linux.h"
 #include "bin/thread.h"
+#include "platform/largefile.h"
 #include "platform/signal_blocker.h"
 
 namespace dart {
@@ -140,10 +141,50 @@ bool SocketBase::GetOption(intptr_t fd,
   return result == 0;
 }
 
+#if defined(__FreeBSD__)
+// FreeBSD rejects MCAST_JOIN_GROUP without an interface index, which is how
+// dart:io asks the kernel to choose the interface. The older interfaces accept
+// an index of 0 for that. dart:io does not pass an interface address here
+// (only on macOS), so use the index based ip_mreqn for IPv4.
+static bool JoinOrLeaveMulticast(intptr_t fd,
+                                 const RawAddr& addr,
+                                 int interfaceIndex,
+                                 bool join) {
+  if (addr.addr.sa_family == AF_INET) {
+    struct ip_mreqn mreq = {};
+    mreq.imr_multiaddr = addr.in.sin_addr;
+    mreq.imr_ifindex = interfaceIndex;
+    return NO_RETRY_EXPECTED(setsockopt(
+               fd, IPPROTO_IP, join ? IP_ADD_MEMBERSHIP : IP_DROP_MEMBERSHIP,
+               &mreq, sizeof(mreq))) == 0;
+  }
+  ASSERT(addr.addr.sa_family == AF_INET6);
+  struct ipv6_mreq mreq = {};
+  mreq.ipv6mr_multiaddr = addr.in6.sin6_addr;
+  mreq.ipv6mr_interface = interfaceIndex;
+  return NO_RETRY_EXPECTED(setsockopt(
+             fd, IPPROTO_IPV6, join ? IPV6_JOIN_GROUP : IPV6_LEAVE_GROUP,
+             &mreq, sizeof(mreq))) == 0;
+}
+
 bool SocketBase::JoinMulticast(intptr_t fd,
                                const RawAddr& addr,
                                const RawAddr&,
                                int interfaceIndex) {
+  return JoinOrLeaveMulticast(fd, addr, interfaceIndex, true);
+}
+
+bool SocketBase::LeaveMulticast(intptr_t fd,
+                                const RawAddr& addr,
+                                const RawAddr&,
+                                int interfaceIndex) {
+  return JoinOrLeaveMulticast(fd, addr, interfaceIndex, false);
+}
+#else
+bool SocketBase::JoinMulticast(intptr_t fd,
+                               const RawAddr& addr,
+                               const RawAddr&,
+                               int interfaceIndex) {
   int proto = addr.addr.sa_family == AF_INET ? IPPROTO_IP : IPPROTO_IPV6;
   struct group_req mreq;
   mreq.gr_interface = interfaceIndex;
@@ -163,6 +204,7 @@ bool SocketBase::LeaveMulticast(intptr_t fd,
   return NO_RETRY_EXPECTED(setsockopt(fd, proto, MCAST_LEAVE_GROUP, &mreq,
                                       sizeof(mreq))) == 0;
 }
+#endif  // defined(__FreeBSD__)
 
 }  // namespace bin
 }  // namespace dart
