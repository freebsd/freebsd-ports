--- src/applyplugin.c.orig	Sat May 11 23:31:00 2002
+++ src/applyplugin.c	Sat May 11 23:31:09 2002
@@ -6,7 +6,7 @@
 /*****************************************************************************/
 
 #include <dlfcn.h>
-#include <endian.h>
+#include <machine/endian.h>
 #include <errno.h>
 #include <math.h>
 #include <stdlib.h>
