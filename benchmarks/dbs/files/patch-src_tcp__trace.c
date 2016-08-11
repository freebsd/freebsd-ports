--- src/tcp_trace.c.orig	1997-05-05 17:02:18 UTC
+++ src/tcp_trace.c
@@ -307,7 +307,7 @@ int act, flg;
 #ifdef _PATH_UNIX
     system = _PATH_UNIX;
 #else    
-    system = "/vmunix";
+    system = "/kernel";
 #endif
 #endif
     
