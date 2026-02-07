--- base64.c.orig	Sun Nov 11 21:52:10 2007
+++ base64.c	Sun Nov 11 21:52:19 2007
@@ -63,13 +63,7 @@
 static int ateof= FALSE;
 static byte dtable[256];
 static int linelength= 0;
-static char eol[]= 
-#ifdef FORCE_BINARY_IO
-"\n"
-#else
-"\r\n"
-#endif
-;
+static char eol[]="\n"; 
 static int errcheck= TRUE;
 
 /*:5*/
