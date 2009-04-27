--- src/templ.c	2009-04-27 10:59:28.000000000 -0500
+++ src/templ.c	2009-04-27 10:59:46.000000000 -0500
@@ -27,6 +27,8 @@
 #include <config.h>
 #ifdef HAVE_MALLOC_H
 #include <malloc.h>
+#else
+#include <stdlib.h>
 #endif
 #include <string.h>
 
