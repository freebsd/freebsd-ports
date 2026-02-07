--- arcam-av/arcam_av.c.orig	2024-06-10 09:18:39 UTC
+++ arcam-av/arcam_av.c
@@ -39,6 +39,8 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 
+#define AF_FILE     AF_UNIX
+
 #define MIN(a, b)     ((a) < (b) ? (a) : (b))
 #define MAX(a, b)     ((a) > (b) ? (a) : (b))
 
