--- src/ui/common/Settings.cxx.orig	Tue Feb 18 10:19:45 2003
+++ src/ui/common/Settings.cxx	Wed Sep 17 00:40:23 2003
@@ -247,7 +247,7 @@
   return true;
 }
 
-void Settings::handleRCFile(istream& in)
+void Settings::handleRCFile(std::istream& in)
 {
   string line, key, value;
   uInt32 equalPos;
