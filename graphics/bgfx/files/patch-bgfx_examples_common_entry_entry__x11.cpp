--- bgfx/examples/common/entry/entry_x11.cpp.orig	2023-11-28 06:38:45 UTC
+++ bgfx/examples/common/entry/entry_x11.cpp
@@ -5,7 +5,7 @@
 
 #include "entry_p.h"
 
-#if ENTRY_CONFIG_USE_NATIVE && (BX_PLATFORM_LINUX || BX_PLATFORM_RPI)
+#if ENTRY_CONFIG_USE_NATIVE && (BX_PLATFORM_LINUX || BX_PLATFORM_BSD || BX_PLATFORM_RPI)
 
 #define XK_MISCELLANY
 #define XK_LATIN1
