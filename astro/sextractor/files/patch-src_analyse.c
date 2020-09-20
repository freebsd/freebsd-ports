--- src/analyse.c.orig	2006-06-29 17:58:03 UTC
+++ src/analyse.c
@@ -23,6 +23,8 @@
 #include	<stdlib.h>
 #include	<string.h>
 
+#define		IN_MAIN
+
 #include	"define.h"
 #include	"globals.h"
 #include	"prefs.h"
@@ -41,7 +43,7 @@
 #include	"som.h"
 #include	"winpos.h"
 
-static obj2struct	*obj2 = &outobj2;
+static obj2struct *obj2 = &outobj2;
 
 /********************************* analyse ***********************************/
 void  analyse(picstruct *field, picstruct *dfield, int objnb,
