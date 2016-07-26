--- src/pulse/introspect.c.orig	2015-09-10 04:51:41 UTC
+++ src/pulse/introspect.c
@@ -22,6 +22,8 @@
 #include <config.h>
 #endif
 
+#include <string.h>
+
 #include <pulse/context.h>
 #include <pulse/direction.h>
 #include <pulse/xmalloc.h>
