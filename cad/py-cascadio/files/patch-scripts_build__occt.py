--- scripts/build_occt.py.orig	2026-07-28 20:10:56 UTC
+++ scripts/build_occt.py
@@ -35,12 +35,14 @@ PLATFORM_LIB_SUBDIR = {
 
 # Platform-specific library paths
 PLATFORM_LIB_SUBDIR = {
+    "FreeBSD": "bsd64/clang/lib",
     "Linux": "lin64/gcc/lib",
     "Darwin": "mac64/clang/lib",
     "Windows": "win64/vc14/lib",
 }
 
 PLATFORM_LIB_NAME = {
+    "FreeBSD": "libTKernel.so",
     "Linux": "libTKernel.so",
     "Darwin": "libTKernel.dylib",
     "Windows": "TKernel.dll",
