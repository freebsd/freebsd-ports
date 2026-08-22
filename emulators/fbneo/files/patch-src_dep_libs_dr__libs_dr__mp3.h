--- src/dep/libs/dr_libs/dr_mp3.h.orig	2026-08-22 01:07:00 UTC
+++ src/dep/libs/dr_libs/dr_mp3.h
@@ -3865,7 +3865,7 @@ static drmp3_result drmp3_fopen(FILE** ppFile, const c
         return drmp3_result_from_errno(err);
     }
 #else
-#if defined(_WIN32) || defined(__APPLE__) || defined(__LIBRETRO__)
+#if defined(_WIN32) || defined(__APPLE__) || defined(__LIBRETRO__) || defined(__FreeBSD__)
     *ppFile = fopen(pFilePath, pOpenMode);
 #else
     #if defined(_FILE_OFFSET_BITS) && _FILE_OFFSET_BITS == 64 && defined(_LARGEFILE64_SOURCE)
