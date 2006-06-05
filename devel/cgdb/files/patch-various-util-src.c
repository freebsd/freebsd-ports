--- various/util/src/pseudo.c.orig	Sun Jun  4 02:09:05 2006
+++ various/util/src/pseudo.c	Mon Jun  5 02:28:30 2006
@@ -46,6 +46,7 @@
 #include <util.h>
 #endif
 #ifdef HAVE_LIBUTIL_H
+#include <inttypes.h>
 #include <libutil.h>
 #endif
 
