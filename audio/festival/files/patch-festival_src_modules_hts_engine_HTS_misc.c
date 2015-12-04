--- festival/src/modules/hts_engine/HTS_misc.c.orig	2013-07-03 19:43:35.000000000 +0600
+++ festival/src/modules/hts_engine/HTS_misc.c	2015-11-22 20:43:30.055818000 +0500
@@ -245,11 +245,7 @@
    } else if (fp->type == HTS_FILE) {
       fpos_t pos;
       fgetpos((FILE *) fp->pointer, &pos);
-#if defined(_WIN32) || defined(__CYGWIN__) || defined(__APPLE__)
       return (size_t) pos;
-#else
-      return (size_t) pos.__pos;
-#endif                          /* _WIN32 || __APPLE__ */
    }
    HTS_error(0, "HTS_ftell: Unknown file type.\n");
    return 0;
