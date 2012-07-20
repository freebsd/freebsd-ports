--- arcam-av/arcam_av.c.orig
+++ arcam-av/arcam_av.c
@@ -27,6 +27,7 @@
 #include <signal.h>
 #include <stddef.h>
 #include <stdio.h>
+#include <string.h>
 #include <termios.h>
 #include <unistd.h>
 
@@ -37,6 +38,8 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 
+#define AF_FILE     AF_UNIX
+
 #define MIN(a, b)     ((a) < (b) ? (a) : (b))
 #define MAX(a, b)     ((a) > (b) ? (a) : (b))
 
