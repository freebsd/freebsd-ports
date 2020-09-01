--- plib/timeout.c.orig	2013-07-04 11:10:49 UTC
+++ plib/timeout.c
@@ -31,7 +31,7 @@
 #ifdef HAVE_THREADS
 
 
-int debug;
+extern int debug;
 
 
 static struct timeout_cb
