--- psycopg/config.h.orig	2008-05-05 17:41:37.000000000 +0200
+++ psycopg/config.h	2008-09-18 13:33:04.000000000 +0200
@@ -129,7 +129,7 @@
 #define inline
 #endif
 
-#if defined(__FreeBSD__) || (defined(_WIN32) && !defined(__GNUC__)) || defined(__sun__) || defined(sun)
+#if (defined(_WIN32) && !defined(__GNUC__)) || defined(__sun__) || defined(sun)
 /* what's this, we have no round function either? */
 static double round(double num)
 {
