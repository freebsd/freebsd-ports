--- bench/util.h.orig	2025-07-17 16:16:38 UTC
+++ bench/util.h
@@ -99,7 +99,7 @@ extern "C" {
 #    define SET_HIGH_PRIORITY /* disabled */
 #  endif
 #  define UTIL_sleep(s) sleep(s)
-#  if defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 199309L)
+#  if defined(__FreeBSD__) || defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 199309L)
 #      define UTIL_sleepMilli(milli) { struct timespec t; t.tv_sec=0; t.tv_nsec=milli*1000000ULL; nanosleep(&t, NULL); }
 #  else
 #      define UTIL_sleepMilli(milli) /* disabled */
@@ -349,7 +349,7 @@ UTIL_STATIC int UTIL_prepareFileList(const char *dirNa
     return nbFiles;
 }
 
-#elif (defined(__APPLE__) && defined(__MACH__)) || \
+#elif (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD__) || \
      ((defined(__unix__) || defined(__unix) || defined(__midipix__)) && defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200112L)) /* snprintf, opendir */
 #  define UTIL_HAS_CREATEFILELIST
 #  include <dirent.h>       /* opendir, readdir */
