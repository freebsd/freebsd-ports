--- net/nettcptransport.cc.orig	2025-05-14 10:21:01 UTC
+++ net/nettcptransport.cc
@@ -63,6 +63,10 @@
 
 # define PEEK_TIMEOUT 200 /* 200 milliseconds */
 
+# if defined(IPPROTO_TCP) && !defined(SOL_TCP)
+# define SOL_TCP IPPROTO_TCP
+# endif
+
 /*
  * Server:
  * p4tunables::list[] has values from the defns in debug.cc + loaded by
