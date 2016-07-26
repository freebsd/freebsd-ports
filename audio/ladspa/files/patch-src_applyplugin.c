--- src/applyplugin.c.orig	2007-11-06 10:52:56 UTC
+++ src/applyplugin.c
@@ -6,7 +6,7 @@
 /*****************************************************************************/
 
 #include <dlfcn.h>
-#include <endian.h>
+#include <machine/endian.h>
 #include <errno.h>
 #include <math.h>
 #include <stdlib.h>
