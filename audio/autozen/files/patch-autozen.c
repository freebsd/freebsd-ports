--- ./autozen.c.orig	2001-09-16 04:09:04.000000000 +0200
+++ ./autozen.c	2012-08-24 12:22:50.546913397 +0200
@@ -27,7 +27,7 @@
  
 /* "The nice thing about standards..." */
 #if defined (__FreeBSD__)
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #else
 #if defined (__NetBSD__) || defined (__OpenBSD__)
 #include <soundcard.h>          /* OSS emulation */
@@ -113,7 +113,7 @@
 //
 /////////////////////////////////
 
-#define SAMPLE_RATE 8000
+#define SAMPLE_RATE 11025
 
 #define MAX_HARMONICS 10
 #define DEFAULT_HARMONICS 3
@@ -253,7 +253,7 @@
 }
 
 
-int CheckSequencer()
+void CheckSequencer()
 {
 char *token;
 int tmp;
@@ -672,7 +672,7 @@
 
 	}	// end while		
 
-return;
+return(NULL);
 }
 
 gint volTimeOut(gpointer data) {
