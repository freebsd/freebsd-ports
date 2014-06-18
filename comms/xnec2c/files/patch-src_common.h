--- src/common.h.orig	2014-06-08 17:50:43.000000000 -0700
+++ src/common.h	2014-06-08 17:50:53.000000000 -0700
@@ -37,6 +37,7 @@
 #include <sys/types.h>
 #include <sys/times.h>
 #include <gtk/gtk.h>
+#include "cexp.h"
 
 /* commonly used complex constants */
 #define	CPLX_00	(0.0+I*0.0)
