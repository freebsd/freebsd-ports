--- lib/guess.c	Tue Jun 24 17:50:29 2003
+++ lib/guess.c	Wed Jun 25 18:15:40 2003
@@ -247,7 +247,7 @@
 
   size_t fchars; /* characters filtered out */
   int cs;
-  ssize_t i;
+  size_t i;
 
   /* Initialize when we are called the first time. */
   if (ascii == ENCA_CS_UNKNOWN) {
