--- src/rrdupdate.c.orig	2014-08-12 20:19:23.000000000 -0400
+++ src/rrdupdate.c	2014-08-12 20:19:50.000000000 -0400
@@ -15,7 +15,12 @@
 #endif
 
 #include "rrd.h"
-#include "plbasename.h"
+
+#ifdef HAVE_LIBGEN_H
+#  include <libgen.h>
+#else
+#  include "plbasename.h"
+#endif
 
 int main(
     int argc,
