--- rpcs3/rpcs3qt/system_info.h.orig	2017-07-17 15:36:54 UTC
+++ rpcs3/rpcs3qt/system_info.h
@@ -1,10 +1,10 @@
 #pragma once
 
+#include <bitset>
 #include <regex>
 
 #ifdef _WIN32
 #include "windows.h"
-#include <bitset>
 typedef unsigned __int32  uint32_t;
 #else
 #include <stdint.h>
