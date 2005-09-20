
$FreeBSD$

--- ksqlanalyzer/tds/config.h.orig
+++ ksqlanalyzer/tds/config.h
@@ -58,6 +58,9 @@
 
 /* Define if you have the atoll function.  */
 #define HAVE_ATOLL 1
+#if __FreeBSD__ < 5
+#undef HAVE_ATOLL
+#endif
 
 /* Define if you have the vasprintf function.  */
 #define HAVE_VASPRINTF 1
