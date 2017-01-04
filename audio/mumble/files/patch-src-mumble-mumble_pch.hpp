--- src/mumble/mumble_pch.hpp.orig	2016-12-12 20:12:12 UTC
+++ src/mumble/mumble_pch.hpp
@@ -42,7 +42,7 @@
 #define ENABLE_SNDFILE_WINDOWS_PROTOTYPES 1
 #endif
 
-#define __int64_t __int64
+#include <sys/types.h>
 #include <sndfile.h>
 #undef __int64_t
 #include <celt.h>
