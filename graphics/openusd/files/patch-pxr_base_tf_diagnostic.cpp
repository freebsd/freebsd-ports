--- pxr/base/tf/diagnostic.cpp.orig	2026-04-24 18:55:54 UTC
+++ pxr/base/tf/diagnostic.cpp
@@ -20,6 +20,7 @@
 #include <cstdio>
 #include <stdexcept>
 #include <csignal>
+#include <unistd.h>
 
 #if defined(ARCH_OS_WASM_VM)
 #include <emscripten.h>
