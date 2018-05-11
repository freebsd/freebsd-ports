--- src/core/regex.cpp.orig	2018-05-10 18:11:45 UTC
+++ src/core/regex.cpp
@@ -31,10 +31,6 @@
 #pragma alloca
 #endif
 
-#if !defined REGEX_MALLOC && !defined __MINGW32__
-#include <alloca.h>
-#endif
-
 #ifndef _GNU_SOURCE
 #define _GNU_SOURCE
 #endif
