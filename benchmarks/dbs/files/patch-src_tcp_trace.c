--- src/tcp_trace.c--	Thu Nov  2 23:00:13 2000
+++ src/tcp_trace.c	Thu Nov  2 23:00:33 2000
@@ -307,7 +307,7 @@
 #ifdef _PATH_UNIX
     system = _PATH_UNIX;
 #else    
-    system = "/vmunix";
+    system = "/kernel";
 #endif
 #endif
     
