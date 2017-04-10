--- higan/target-tomoko/tools/cheat-database.cpp.orig	2016-05-03 22:40:39 UTC
+++ higan/target-tomoko/tools/cheat-database.cpp
@@ -18,7 +18,7 @@ auto CheatDatabase::findCodes() -> void 
   if(!emulator) return;
   auto sha256 = emulator->sha256();
 
-  auto contents = string::read(locate("cheats.bml"));
+  auto contents = string::read(locateShared("cheats.bml"));
   auto document = BML::unserialize(contents);
 
   for(auto cartridge : document.find("cartridge")) {
