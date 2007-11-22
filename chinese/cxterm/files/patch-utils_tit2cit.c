--- utils/tit2cit.c.orig	1995-02-14 06:53:17.000000000 +0100
+++ utils/tit2cit.c	2007-11-22 14:41:59.000000000 +0100
@@ -53,8 +53,7 @@
 #include <X11/Xos.h>	/* OS dependent stuff */
 #include <ctype.h>
 #include <stdio.h>
-
-extern char *malloc(), *calloc(), *realloc();
+#include <stdlib.h>
 
 extern int HZencode();		/* from HZutil.o */
 extern int HZgetprompt();	/* from HZutil.o */
