--- higan/target-tomoko/tomoko.hpp.orig	2017-01-11 11:35:22 UTC
+++ higan/target-tomoko/tomoko.hpp
@@ -18,4 +18,5 @@ extern Emulator::Interface* emulator;
 #include "tools/tools.hpp"
 #include "presentation/presentation.hpp"
 
+auto locateShared(string name) -> string;
 auto locate(string name) -> string;
