--- Help/axinfo.c.orig	Fri May 10 22:26:46 2002
+++ Help/axinfo.c	Fri May 10 22:27:13 2002
@@ -45,7 +45,7 @@
 #include <stdio.h>
 
 extern char *getenv();
-extern char *malloc(), *realloc();
+extern void *malloc(), *realloc();
 
 #include "Confirmer.h"
 #include "Hyper.h"
