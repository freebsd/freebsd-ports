--- psycopg/config.h.orig	2009-02-16 09:57:03.000000000 +0100
+++ psycopg/config.h	2009-03-01 10:59:26.000000000 +0100
@@ -129,7 +129,7 @@
 #define inline
 #endif
 
-#if (defined(__FreeBSD__) && __FreeBSD_version < 503000) || (defined(_WIN32) && !defined(__GNUC__)) || defined(__sun__) || defined(sun)
+#if (defined(_WIN32) && !defined(__GNUC__)) || defined(__sun__) || defined(sun)
 /* what's this, we have no round function either? */
 static double round(double num)
 {
