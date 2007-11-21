--- src/jp.c.orig	2007-11-05 07:53:44.000000000 -0500
+++ src/jp.c	2007-11-05 07:54:18.000000000 -0500
@@ -27,6 +27,7 @@
 #if defined(UNIX) && !defined(GENERAL)
 #include "signal.h"
 
+	static void abend_handler();
 /*
  *	handle core dump by some bugs.
  */
@@ -34,7 +35,6 @@
 core_handler(dummy)
 	int dummy;
 {
-	static void abend_handler();
 	abend_handler(TRUE);
 }
 
@@ -42,7 +42,6 @@
 hup_handler(dummy)
 	int dummy;
 {
-	static void abend_handler();
 	abend_handler(FALSE);
 }
 


