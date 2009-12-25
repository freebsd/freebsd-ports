--- src/arch/unix/dynlib.c.orig	2009-10-21 18:46:46.000000000 +0200
+++ src/arch/unix/dynlib.c	2009-12-25 19:00:10.000000000 +0100
@@ -51,6 +51,8 @@
 
 #else
 
+#include <string.h>
+
 void *vice_dynlib_open(const char *name)
 {
     return NULL;
