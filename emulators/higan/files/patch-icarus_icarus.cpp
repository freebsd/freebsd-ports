--- icarus/icarus.cpp.orig	2017-01-11 13:07:07 UTC
+++ icarus/icarus.cpp
@@ -4,6 +4,20 @@ using namespace nall;
 #include <hiro/hiro.hpp>
 using namespace hiro;
 
+auto locateShared(string name) -> string {
+  string location = {Path::program(), name};
+  if(inode::exists(location)) return location;
+
+  location = {Path::shared(), "icarus/", name}; 
+  if(inode::exists(location)) return location;
+
+  location = {Path::config(), "icarus/", name};
+  if(inode::exists(location)) return location;
+
+  directory::create({Path::local(), "icarus/"});
+  return {Path::local(), "icarus/", name};
+}
+
 auto locate(string name) -> string {
   string location = {Path::program(), name};
   if(inode::exists(location)) return location;
