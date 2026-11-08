--- src/unrardll/wrapper.cpp.orig	2026-10-30 13:57:42 UTC
+++ src/unrardll/wrapper.cpp
@@ -16,7 +16,7 @@
 #else
 #include <unistd.h>
 #endif
-#include <unrar/dll.hpp>
+#include <libunrar/dll.hpp>
 #include <errno.h>
 
 #define CALLBACK_ERROR_SZ 256
