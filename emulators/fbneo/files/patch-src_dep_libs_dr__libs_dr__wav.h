--- src/dep/libs/dr_libs/dr_wav.h.orig	2026-08-22 01:07:22 UTC
+++ src/dep/libs/dr_libs/dr_wav.h
@@ -5214,7 +5214,7 @@ DRWAV_PRIVATE drwav_result drwav_fopen(FILE** ppFile, 
         return drwav_result_from_errno(err);
     }
 #else
-#if defined(_WIN32) || defined(__APPLE__)
+#if defined(_WIN32) || defined(__APPLE__) || defined(__FreeBSD__)
     *ppFile = fopen(pFilePath, pOpenMode);
 #else
     #if defined(_FILE_OFFSET_BITS) && _FILE_OFFSET_BITS == 64 && defined(_LARGEFILE64_SOURCE)
