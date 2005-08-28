--- quote.c.orig	Wed May 25 04:14:24 2005
+++ quote.c	Thu Aug  4 22:34:26 2005
@@ -307,7 +307,7 @@
  	dest = result;
 	
 	Copy("'", dest++, 1, char);
-	strncpy(dest,intermead,strlen(intermead));
+	strncpy(dest,intermead,strlen(intermead)+1);
 	strcat(dest,"\'");
 	
 #if PGLIBVERSION >= 70400
