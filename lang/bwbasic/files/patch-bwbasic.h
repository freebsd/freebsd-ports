--- bwbasic.h.orig	2010-01-25 10:25:35.000000000 +0800
+++ bwbasic.h	2010-01-25 10:27:15.000000000 +0800
@@ -111,10 +111,16 @@
 ***************************************************************/
 
 #ifdef __STDC__
+#ifndef HAVE_RAISE
 #define HAVE_RAISE TRUE
+#endif
+#ifndef HAVE_STRING
 #define HAVE_STRING TRUE
+#endif
+#ifndef HAVE_STDLIB
 #define HAVE_STDLIB TRUE
 #endif
+#endif
 
 #ifdef __STDC__
 #define	HAVE_SIGNAL	TRUE
