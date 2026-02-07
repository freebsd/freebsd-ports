--- src/kj/async-io-unix.c++.orig	2021-08-14 23:27:30 UTC
+++ src/kj/async-io-unix.c++
@@ -1486,7 +1486,11 @@ kj::Own<PeerIdentity> SocketAddress::getIdentity(kj::L
       // MacOS / FreeBSD
       struct xucred creds;
       uint length = sizeof(creds);
+#if defined SOL_LOCAL
       stream.getsockopt(SOL_LOCAL, LOCAL_PEERCRED, &creds, &length);
+#else
+      stream.getsockopt(0, LOCAL_PEERCRED, &creds, &length);
+#endif
       KJ_ASSERT(length == sizeof(creds));
       if (creds.cr_uid != static_cast<uid_t>(-1)) {
         result.uid = creds.cr_uid;
