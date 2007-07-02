--- psycopg/config.h.orig	2007-04-11 12:12:37.000000000 +0000
+++ psycopg/config.h	2007-07-02 14:41:35.000000000 +0000
@@ -113,7 +113,7 @@
 #define inline
 #endif
 
-#if defined(__FreeBSD__) || (defined(_WIN32) && !defined(__GNUC__)) || defined(__sun__)
+#if (defined(_WIN32) && !defined(__GNUC__)) || defined(__sun__)
 /* what's this, we have no round function either? */
 static double round(double num)
 {
