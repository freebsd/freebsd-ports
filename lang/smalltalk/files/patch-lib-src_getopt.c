--- lib-src/getopt.c.orig	2013-03-23 19:56:26 UTC
+++ lib-src/getopt.c
@@ -43,6 +43,8 @@
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 
 /* Comment out all this code if we are using the GNU C Library, and are not
    actually compiling the library itself.  This code is part of the GNU C
