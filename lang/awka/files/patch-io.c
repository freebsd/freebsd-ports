--- lib/io.c.orig	Mon May  6 17:32:36 2002
+++ lib/io.c	Mon May  6 17:32:58 2002
@@ -19,6 +19,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <errno.h>
+#include <sys/types.h>
 
 #define _IO_C
 #define _IN_LIBRARY
