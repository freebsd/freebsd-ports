--- lib/HTS_misc.c.orig	2015-12-25 00:12:53 UTC
+++ lib/HTS_misc.c
@@ -245,7 +245,7 @@ size_t HTS_ftell(HTS_File * fp)
    } else if (fp->type == HTS_FILE) {
       fpos_t pos;
       fgetpos((FILE *) fp->pointer, &pos);
-#if defined(_WIN32) || defined(__CYGWIN__) || defined(__APPLE__) || defined(__ANDROID__)
+#if defined(_WIN32) || defined(__CYGWIN__) || defined(__APPLE__) || defined(__ANDROID__) || defined(__FreeBSD__)
       return (size_t) pos;
 #else
       return (size_t) pos.__pos;
