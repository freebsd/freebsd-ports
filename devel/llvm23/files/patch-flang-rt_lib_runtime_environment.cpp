--- flang-rt/lib/runtime/environment.cpp.orig
+++ flang-rt/lib/runtime/environment.cpp
@@ -18,6 +18,7 @@
 #ifdef _WIN32
 extern char **_environ;
 #elif defined(__FreeBSD__)
+#include <dlfcn.h>
 // FreeBSD has environ in crt rather than libc. Using "extern char** environ"
 // in the code of a shared library makes it fail to link with -Wl,--no-undefined
 // See https://reviews.freebsd.org/D30842#840642
