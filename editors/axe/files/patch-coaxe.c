--- coaxe.c.orig	Fri May 10 22:28:40 2002
+++ coaxe.c	Fri May 10 22:28:53 2002
@@ -38,7 +38,7 @@
 #endif
 #include <stdio.h>
 extern char *getenv();
-extern char *malloc(), *realloc();
+extern void *malloc(), *realloc();
 
 #include "util.h"
 
