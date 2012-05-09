--- font/fontx2.c.orig	1997-01-24 19:08:56.000000000 +0900
+++ font/fontx2.c	2012-05-10 00:14:28.719647899 +0900
@@ -37,6 +37,7 @@
 #include	<string.h>
 #include	<sys/socket.h>
 
+#include	<defs.h>
 #include	<interface.h>
 #include	<fnld.h>
 
@@ -170,7 +171,7 @@
 	    font = FontLoadSFontx(fp, header);
 	else exit(0);
     }
-    free(header);
+    SafeFree(header);
     return(font);
 }
 
