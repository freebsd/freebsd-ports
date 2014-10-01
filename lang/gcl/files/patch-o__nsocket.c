--- o/nsocket.c.orig
+++ o/nsocket.c
@@ -328,7 +328,7 @@
 
 
 
-#define SOCKET_FD(strm) ((strm)->sm.sm_fp ? fileno((strm)->sm.sm_fp) : -1)
+#define SOCKET_FD(strm) ((strm)->sm.sm_fp ? fileno((FILE *)(strm)->sm.sm_fp) : -1)
 
 static void
 check_socket(object x)
