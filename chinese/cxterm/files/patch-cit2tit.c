--- utils/cit2tit.c.orig	Fri Oct 25 11:56:53 2002
+++ utils/cit2tit.c	Fri Oct 25 11:57:01 2002
@@ -29,8 +29,6 @@
 #include <ctype.h>
 #include <stdio.h>
 
-extern char *malloc(), *calloc(), *realloc();
-
 extern char *HZencodeName();	/* from HZutil.c */
 
 #include "HZtable.h"
