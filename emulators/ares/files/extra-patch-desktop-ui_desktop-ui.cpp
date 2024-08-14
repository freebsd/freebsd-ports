--- desktop-ui/desktop-ui.cpp.orig	2024-07-28 14:18:09 UTC
+++ desktop-ui/desktop-ui.cpp
@@ -22,6 +22,12 @@ auto locate(const string& name) -> string {
   location = {Path::sharedData(), "ares/", name};
   if(inode::exists(location)) return location;
 
+  // 3a. The thirdparty shaders directory
+  if(name == "Shaders/") {
+    location = "@@SHADERS@@";
+    if(inode::exists(location)) return location;
+  }
+
   // 4. The application bundle resource directory (macOS only)
 #if defined(PLATFORM_MACOS)
   location = {Path::resources(), name};
