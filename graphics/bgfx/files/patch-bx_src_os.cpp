--- bx/src/os.cpp.orig	2023-12-04 22:32:30 UTC
+++ bx/src/os.cpp
@@ -7,6 +7,10 @@
 #include <bx/os.h>
 #include <bx/uint32_t.h>
 
+#include <time.h>
+#include <dlfcn.h>
+#include <sched.h>
+
 #if BX_CRT_MSVC
 #	include <direct.h>
 #else
