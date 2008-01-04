--- src/pulse/introspect.c.orig	2008-01-03 20:01:31.000000000 -0500
+++ src/pulse/introspect.c	2008-01-03 20:01:39.000000000 -0500
@@ -26,6 +26,8 @@
 #include <config.h>
 #endif
 
+#include <string.h>
+
 #include <pulse/context.h>
 
 #include <pulsecore/gccmacro.h>
