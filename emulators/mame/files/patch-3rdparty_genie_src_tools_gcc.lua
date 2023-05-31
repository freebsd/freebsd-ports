--- 3rdparty/genie/src/tools/gcc.lua.orig	2023-05-25 09:19:09 UTC
+++ 3rdparty/genie/src/tools/gcc.lua
@@ -12,9 +12,9 @@ --
 -- Set default tools
 --
 
-	premake.gcc.cc     = "gcc"
-	premake.gcc.cxx    = "g++"
-	premake.gcc.ar     = "ar"
+	premake.gcc.cc     = _OPTIONS["CC"]
+	premake.gcc.cxx    = _OPTIONS["CXX"]
+	premake.gcc.ar     = _OPTIONS["AR"]
 	premake.gcc.rc     = "windres"
 	premake.gcc.llvm   = false
 
