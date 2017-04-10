--- higan/target-tomoko/tomoko.cpp.orig	2016-07-01 08:21:27 UTC
+++ higan/target-tomoko/tomoko.cpp
@@ -4,6 +4,20 @@ unique_pointer<Audio> audio;
 unique_pointer<Input> input;
 Emulator::Interface* emulator = nullptr;
 
+auto locateShared(string name) -> string {
+  string location = {Path::program(), name};
+  if(inode::exists(location)) return location;
+
+  location = {Path::shared(), "higan/", name};
+  if(inode::exists(location)) return location;
+
+  location = {Path::config(), "higan/", name};
+  if(inode::exists(location)) return location;
+
+  directory::create({Path::local(), "higan/"});
+  return {Path::local(), "higan/", name};
+}
+
 auto locate(string name) -> string {
   string location = {Path::program(), name};
   if(inode::exists(location)) return location;
