--- rtgui/cachemanager.cc.orig	2017-01-26 22:12:22 UTC
+++ rtgui/cachemanager.cc
@@ -36,7 +36,7 @@ namespace
 {
 
 constexpr auto cacheDirMode = 511;
-constexpr auto cacheDirs = { "profiles", "images", "aehistograms", "embprofiles", "data" };
+constexpr const char *cacheDirs[] = { "profiles", "images", "aehistograms", "embprofiles", "data" };
 
 }
 
