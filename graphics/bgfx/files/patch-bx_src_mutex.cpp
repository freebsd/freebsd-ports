--- bx/src/mutex.cpp.orig	2023-12-04 22:18:54 UTC
+++ bx/src/mutex.cpp
@@ -5,6 +5,8 @@
 
 #include <bx/mutex.h>
 
+#include <pthread.h>
+
 #if BX_CONFIG_SUPPORTS_THREADING
 
 #if BX_CRT_NONE
