--- main.c.orig	2014-01-09 17:47:52.000000000 +0000
+++ main.c	2014-01-09 17:47:38.000000000 +0000
@@ -25,6 +25,14 @@
 
 #include "gdbstub.h"
 
+static void *oom_check(void *ptr)
+{
+    if (ptr == NULL) {
+        abort();
+    }
+    return ptr;
+}
+
 static x49gp_t *x49gp;
 
 #ifdef QEMU_OLD // LD TEMPO HACK
