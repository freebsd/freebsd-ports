--- 3rdparty/rapidyaml/include/c4/yml/common.hpp.orig	2026-01-28 16:36:27 UTC
+++ 3rdparty/rapidyaml/include/c4/yml/common.hpp
@@ -11,6 +11,8 @@
 
 #if defined(C4_MSVC) || defined(C4_MINGW) || defined(_WIN32) || defined(C4_WIN)
 #include <malloc.h>
+#elif defined(__FreeBSD__)
+#include <stdlib.h>
 #else
 #include <alloca.h>
 #endif
