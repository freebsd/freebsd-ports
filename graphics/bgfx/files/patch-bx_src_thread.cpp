--- bx/src/thread.cpp.orig	2023-12-04 22:36:27 UTC
+++ bx/src/thread.cpp
@@ -6,6 +6,8 @@
 #include <bx/os.h>
 #include <bx/thread.h>
 
+#include <pthread.h>
+
 #if BX_CONFIG_SUPPORTS_THREADING
 
 #if BX_PLATFORM_WINDOWS && !BX_CRT_NONE
