
$FreeBSD$

--- gconf/gconf-internals.c	2001/11/07 11:27:13	1.1
+++ gconf/gconf-internals.c	2001/11/07 11:27:52
@@ -28,6 +28,9 @@
 #include <string.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
