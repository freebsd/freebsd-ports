--- w_wad.c	Sat Oct 23 05:02:21 1999
+++ w_wad.c.new	Sun Feb 13 03:52:25 2000
@@ -15,7 +15,6 @@
 #include <string.h>
 #include <unistd.h>
 #include <stdlib.h>
-#include <malloc.h>
 #include <assert.h>
 #include <fcntl.h>
 #include <sys/stat.h>
@@ -26,8 +25,6 @@
 
 #define O_BINARY		0
 #endif   /* UNIX */
-
-#include <malloc.h>
 
 #ifdef __GLIBC__
 #include <sys/io.h>
