--- ./XGP/GTKViewer.c.orig	Sun Aug 20 14:19:48 2006
+++ ./XGP/GTKViewer.c	Sun Aug 20 14:19:58 2006
@@ -40,7 +40,7 @@
 
 #include <stdio.h>
 #include <errno.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 
 #include <dlfcn.h>
