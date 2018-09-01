--- src/openhbci/api.cpp.orig	2018-09-01 02:43:47 UTC
+++ src/openhbci/api.cpp
@@ -1260,7 +1260,7 @@ void API::_addPluginsFromDirs(Pointer<MediumPluginList
 	  goon=false;
 	else {
 	  if (-1!=parser::cmpPattern(entry,
-				     "*"PLUGIN_EXT,
+				     "*" PLUGIN_EXT,
 				     false)) {
 	    Pointer<MediumPluginFile> mpf;
 
