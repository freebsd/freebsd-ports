--- XmysqlDB.c.orig	Tue Nov 19 13:21:10 2002
+++ XmysqlDB.c	Tue Nov 19 13:25:49 2002
@@ -3,7 +3,6 @@
 #include "Xmysql_def.h"
 
 /* prototypes */
-char *strmov (char *dst, const char *src);
 char *strfill (char *s, uint len, int fill);
 
 /* this macro is used to make sure all returns clean up resources */
@@ -800,7 +799,7 @@
 								}
 							}
 							else {
-								pos = strmov (pos, "NULL");
+								pos = strcpy (pos, "NULL");
 								if (maxLen > 4)
 									pos = strfill (pos, maxLen - 4, ' ');
 							}
