--- w_wad.c.orig	2003-12-08 23:10:35 UTC
+++ w_wad.c
@@ -15,7 +15,6 @@
 #include <string.h>
 #include <unistd.h>
 #include <stdlib.h>
-#include <malloc.h>
 #include <assert.h>
 #include <fcntl.h>
 #include <sys/stat.h>
@@ -27,8 +26,6 @@
 #define O_BINARY		0
 #endif   /* UNIX */
 
-#include <malloc.h>
-
 #ifdef __GLIBC__
 /* kludge for broken asm-sparc/io.h on linux 2.2.14.? */
 #ifdef __sparc__
