--- src/ls_firebird.c.orig	2016-06-24 14:06:19 UTC
+++ src/ls_firebird.c
@@ -6,7 +6,7 @@
 
 #include <ibase.h>	/* The Firebird API*/
 #include <time.h>	/* For managing time values */
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 
 /* Lua API */
