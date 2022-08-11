--- third_party/skia/src/ports/SkOSFile_stdio.cpp.orig	2022-05-11 07:17:54 UTC
+++ third_party/skia/src/ports/SkOSFile_stdio.cpp
@@ -130,7 +130,7 @@ void sk_fflush(FILE* f) {
 
 void sk_fsync(FILE* f) {
 #if !defined(_WIN32) && !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__) \
-        && !defined(_NEWLIB_VERSION)
+        && !defined(_NEWLIB_VERSION) && !defined(__OpenBSD__)
     int fd = fileno(f);
     fsync(fd);
 #endif
