--- eb/match.c.orig	Tue Aug 14 10:04:25 2001
+++ eb/match.c	Sat Mar  1 02:34:57 2003
@@ -43,7 +43,7 @@
 
     for (;;) {
 	if (length <= i) {
-	    result = *word_p;
+	    result = 0;
 	    break;
 	}
 	if (*word_p == '\0') {
@@ -92,7 +92,7 @@
 
     for (;;) {
 	if (length <= i) {
-	    result = *word_p;
+	    result = 0;
 	    break;
 	}
 	if (*word_p == '\0') {
