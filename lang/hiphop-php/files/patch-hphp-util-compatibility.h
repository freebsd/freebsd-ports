--- hphp/util/compatibility.h.orig	2013-07-21 12:48:18.383655924 +0200
+++ hphp/util/compatibility.h	2013-07-21 12:48:34.993417921 +0200
@@ -24,7 +24,7 @@
 
 #define PHP_DIR_SEPARATOR '/'
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
 char *strndup(const char* str, size_t len);
 int dprintf(int fd, const char *format, ...) ATTRIBUTE_PRINTF(2,3);
 typedef int clockid_t;
