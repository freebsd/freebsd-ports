--- utils/cit2tit.c.orig	1995-01-17 11:59:13.000000000 +0100
+++ utils/cit2tit.c	2007-11-22 14:42:32.000000000 +0100
@@ -28,8 +28,7 @@
 #include <X11/Xos.h>	/* OS dependent stuff */
 #include <ctype.h>
 #include <stdio.h>
-
-extern char *malloc(), *calloc(), *realloc();
+#include <stdlib.h>
 
 extern char *HZencodeName();	/* from HZutil.c */
 
