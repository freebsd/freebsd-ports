--- thrift/lib/cpp2/server/Cpp2ConnContext.cpp.orig	2020-09-10 00:42:26 UTC
+++ thrift/lib/cpp2/server/Cpp2ConnContext.cpp
@@ -51,7 +51,7 @@ Cpp2ConnContext::PeerCred Cpp2ConnContext::PeerCred::q
   } else {
     return PeerCred{cred.pid, cred.uid, cred.gid};
   }
-#elif defined(LOCAL_PEERCRED) // macOS
+#elif defined(LOCAL_PEERCRED) && defined(LOCAL_PEEREPID) // macOS
   struct xucred cred = {};
   pid_t epid = 0;
   socklen_t len;
