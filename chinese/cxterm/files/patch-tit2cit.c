--- utils/tit2cit.c.orig	Fri Oct 25 11:54:40 2002
+++ utils/tit2cit.c	Fri Oct 25 11:54:50 2002
@@ -54,8 +54,6 @@
 #include <ctype.h>
 #include <stdio.h>
 
-extern char *malloc(), *calloc(), *realloc();
-
 extern int HZencode();		/* from HZutil.o */
 extern int HZgetprompt();	/* from HZutil.o */
 
