--- 3rdparty/hts_engine_API/lib/HTS_misc.c.orig	2016-03-04 22:01:27.406278681 +0000
+++ 3rdparty/hts_engine_API/lib/HTS_misc.c	2016-03-04 22:01:51.791013177 +0000
@@ -245,7 +245,7 @@
    } else if (fp->type == HTS_FILE) {
       fpos_t pos;
       fgetpos((FILE *) fp->pointer, &pos);
-#if defined(_WIN32) || defined(__CYGWIN__) || defined(__APPLE__) || defined(__ANDROID__)
+#if defined(_WIN32) || defined(__CYGWIN__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__ANDROID__)
       return (size_t) pos;
 #else
       return (size_t) pos.__pos;
