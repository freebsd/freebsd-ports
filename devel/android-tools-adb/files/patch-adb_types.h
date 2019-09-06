--- adb/types.h.orig	2019-07-17 19:54:09 UTC
+++ adb/types.h
@@ -16,6 +16,7 @@
 
 #pragma once
 
+#include <cstring> // memcpy for GCC
 #include <algorithm>
 #include <deque>
 #include <memory>
