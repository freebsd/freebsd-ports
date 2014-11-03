--- 3rdparty/hts_engine_API/lib/HTS_misc.c.orig	2014-10-21 18:20:10.716009721 +0200
+++ 3rdparty/hts_engine_API/lib/HTS_misc.c	2014-10-21 18:21:32.200933884 +0200
@@ -245,7 +245,7 @@
    } else if (fp->type == HTS_FILE) {
       fpos_t pos;
       fgetpos((FILE *) fp->pointer, &pos);
-#if defined(_WIN32) || defined(__CYGWIN__) || defined(__APPLE__) || defined(__ANDROID__)
+#if defined(_WIN32) || defined(__CYGWIN__) || defined(__APPLE__) || defined(__ANDROID__) || defined(__FreeBSD__)
       return (size_t) pos;
 #else
       return (size_t) pos.__pos;
