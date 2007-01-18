--- psycopg/config.h.orig	Thu Jan 18 01:23:39 2007
+++ psycopg/config.h	Thu Jan 18 01:24:57 2007
@@ -102,7 +102,7 @@
 #define inline
 #endif
 
-#if defined(__FreeBSD__) || defined(_WIN32) || defined(__sun__)
+#if defined(_WIN32) || defined(__sun__)
 /* what's this, we have no round function either? */
 static double round(double num)
 {
