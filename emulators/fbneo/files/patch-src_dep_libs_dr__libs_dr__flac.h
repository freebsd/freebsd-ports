--- src/dep/libs/dr_libs/dr_flac.h.orig	2026-08-22 01:07:12 UTC
+++ src/dep/libs/dr_libs/dr_flac.h
@@ -8677,7 +8677,7 @@ static drflac_result drflac_fopen(FILE** ppFile, const
         return drflac_result_from_errno(err);
     }
 #else
-#if defined(_WIN32) || defined(__APPLE__) || defined(__LIBRETRO__)
+#if defined(_WIN32) || defined(__APPLE__) || defined(__LIBRETRO__) || defined(__FreeBSD__)
     *ppFile = fopen(pFilePath, pOpenMode);
 #else
     #if defined(_FILE_OFFSET_BITS) && _FILE_OFFSET_BITS == 64 && defined(_LARGEFILE64_SOURCE)
