--- src/asmjit/core/virtmem.cpp.orig	2020-01-10 05:11:38 UTC
+++ src/asmjit/core/virtmem.cpp
@@ -9,6 +9,8 @@
 #include "../core/build.h"
 #ifndef ASMJIT_NO_JIT
 
+#include <sys/stat.h>
+
 #include "../core/osutils.h"
 #include "../core/string.h"
 #include "../core/support.h"
