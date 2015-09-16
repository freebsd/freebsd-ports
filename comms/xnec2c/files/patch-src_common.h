--- src/common.h.orig	2015-04-10 07:22:25 UTC
+++ src/common.h
@@ -37,6 +37,7 @@
 #include <sys/types.h>
 #include <sys/times.h>
 #include <gtk/gtk.h>
+#include "cexp.h"
 
 /* commonly used complex constants */
 #define	CPLX_00	(0.0+I*0.0)
