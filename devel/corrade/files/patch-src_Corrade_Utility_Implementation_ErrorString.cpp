--- src/Corrade/Utility/Implementation/ErrorString.cpp.orig	2023-01-16 01:30:29 UTC
+++ src/Corrade/Utility/Implementation/ErrorString.cpp
@@ -60,7 +60,7 @@ void printErrnoErrorString(Debug& debug, const int err
        idea. The POSIX variant returns int(0) on success, while the GNU variant
        may return a pointer to a statically allocated string instead of filling
        the buffer. Sigh. */
-    #if ((_POSIX_C_SOURCE >= 200112L) && !_GNU_SOURCE) || defined(CORRADE_TARGET_EMSCRIPTEN) || defined(CORRADE_TARGET_APPLE)
+    #if ((_POSIX_C_SOURCE >= 200112L) && !_GNU_SOURCE) || defined(CORRADE_TARGET_EMSCRIPTEN) || defined(CORRADE_TARGET_APPLE) || defined(__FreeBSD__)
     char string[256];
     CORRADE_INTERNAL_ASSERT_OUTPUT(strerror_r(error, string, Containers::arraySize(string)) == 0);
     #else
