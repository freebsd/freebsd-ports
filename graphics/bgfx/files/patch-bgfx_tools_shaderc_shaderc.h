--- bgfx/tools/shaderc/shaderc.h.orig	2023-01-06 21:05:59 UTC
+++ bgfx/tools/shaderc/shaderc.h
@@ -15,7 +15,7 @@ namespace bgfx
 #	define SHADERC_CONFIG_HLSL BX_PLATFORM_WINDOWS
 #endif // SHADERC_CONFIG_HLSL
 
-#include <alloca.h>
+//#include <alloca.h>
 #include <stdint.h>
 #include <string.h>
 #include <algorithm>
