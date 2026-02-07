--- src/tools/gcc.lua.orig	2023-11-11 05:52:50 UTC
+++ src/tools/gcc.lua
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
 
@@ -35,7 +35,7 @@ --
 		FloatFast        = "-ffast-math",
 		FloatStrict      = "-ffloat-store",
 		NoFramePointer   = "-fomit-frame-pointer",
-		Optimize         = "-O2",
+		Optimize         = "",
 		OptimizeSize     = "-Os",
 		OptimizeSpeed    = "-O3",
 		Symbols          = "-g",
