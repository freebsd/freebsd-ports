--- Robot/rfitsc.c.orig	2009-04-11 22:08:21.000000000 +0200
+++ Robot/rfitsc.c	2009-04-11 22:09:22.000000000 +0200
@@ -2,6 +2,7 @@
 #include <fcntl.h>
 #include <sys/file.h>
 #include <unistd.h>
+#include <stdlib.h>
 
 #define BLOCK 2880
 
