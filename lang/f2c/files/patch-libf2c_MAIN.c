--- libf2c/MAIN.c.orig	2020-12-05 22:19:12 UTC
+++ libf2c/MAIN.c
@@ -0,0 +1,18 @@
+/*
+   Add a pseudo entry point for cases where the main FOTRAN program is missing
+   e.g. ports/cad/tochnog.
+
+   Credit: adapted from Sergio Gelato <gelato (at) sissa.it> on Usenet.
+*/
+
+#include <stdio.h>
+#include <stdlib.h>
+#include <sys/cdefs.h>
+
+__weak_reference(missing_MAIN__,MAIN__);
+
+void missing_MAIN__ (void)
+{
+    fprintf(stderr, "The Fortran main program is missing.\n");
+    abort();
+}
