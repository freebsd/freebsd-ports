Patch by Matthias Andree <mandree@freebsd.org> 2025-07-15
to enable using 64-bit file I/O API such as ftello
that use off_t types.

--- utils/miniz.cpp.orig	2022-01-14 09:19:07 UTC
+++ utils/miniz.cpp
@@ -3022,7 +3022,7 @@ static FILE *mz_freopen(const char *pPath, const char 
 #define MZ_FFLUSH fflush
 #define MZ_FREOPEN(p, m, s) freopen64(p, m, s)
 #define MZ_DELETE_FILE remove
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 #ifndef MINIZ_NO_TIME
 #include <utime.h>
 #endif
