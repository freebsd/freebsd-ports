--- src/PluginPaths.cpp.orig	2020-10-22 23:20:06 UTC
+++ src/PluginPaths.cpp
@@ -214,7 +214,7 @@ PluginPaths::PluginPaths()
     else if (g_Platform->isFlatpacked()) {
         initFlatpackPaths();
     }
-    else if (osSystemId & wxOS_UNIX_LINUX) {
+    else if (osSystemId & wxOS_UNIX_LINUX || osSystemId & wxOS_UNIX_FREEBSD) {
 #ifdef __OCPN__ANDROID__
         initAndroidPaths();
 #else
