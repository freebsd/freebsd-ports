--- src/3rdparty/assimp/src/contrib/zip/src/miniz.h.orig	2021-10-21 09:07:21 UTC
+++ src/3rdparty/assimp/src/contrib/zip/src/miniz.h
@@ -4201,8 +4201,8 @@ static FILE *mz_freopen(const char *pPath, const char 
 #define MZ_FWRITE fwrite
 #define MZ_FTELL64 ftello64
 #define MZ_FSEEK64 fseeko64
-#define MZ_FILE_STAT_STRUCT stat64
-#define MZ_FILE_STAT stat64
+#define MZ_FILE_STAT_STRUCT stat
+#define MZ_FILE_STAT stat
 #define MZ_FFLUSH fflush
 #define MZ_FREOPEN(p, m, s) freopen64(p, m, s)
 #define MZ_DELETE_FILE remove
