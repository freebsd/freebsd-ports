--- libs/ardour/plugin_manager.cc.orig	2021-08-13 16:20:07 UTC
+++ libs/ardour/plugin_manager.cc
@@ -87,6 +87,7 @@
 #include "ardour/search_paths.h"
 
 #if (defined WINDOWS_VST_SUPPORT || defined MACVST_SUPPORT || defined LXVST_SUPPORT)
+#include "ardour/system_exec.h"
 #include "ardour/vst2_scan.h"
 #endif
 
@@ -113,6 +114,7 @@
 
 #include "ardour/audio_unit.h"
 #include "ardour/auv2_scan.h"
+#include "ardour/system_exec.h"
 #include <Carbon/Carbon.h>
 #endif
 
