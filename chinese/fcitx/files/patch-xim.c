--- xim.c.orig	Tue Jan  6 14:12:11 2004
+++ xim.c	Thu Oct 14 23:21:07 2004
@@ -336,7 +336,7 @@
     char           *ps;
 
     if (bIsUtf8) {
-	int             l1, l2;
+	size_t          l1, l2;
 
 	ps = strOutput;
 	l1 = strlen (strHZ);
