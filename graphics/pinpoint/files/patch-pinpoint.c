--- pinpoint.c.orig	2011-05-23 07:49:55.000000000 -0500
+++ pinpoint.c	2011-06-26 04:23:53.780817124 -0500
@@ -31,6 +31,21 @@
 
 #include "pinpoint.h"
 
+#ifndef __GLIBC__
+/* ref: http://lists.freebsd.org/pipermail/freebsd-ports/2009-June/055131.html */
+
+char *strchrnul(const char *s, int c) {
+  char *i;
+  for (i = (char*)s; *i != '\0'; ++i) {
+    if (*i == c) {
+      return i;
+    }
+  }
+  return i;
+}
+
+#endif
+
 GList *pp_slides      = NULL; /* list of slide text */
 GList *pp_slidep      = NULL; /* current slide */
 
