--- interpreter/cling/lib/Interpreter/CIFactory.cpp.orig	2024-04-14 12:10:55 UTC
+++ interpreter/cling/lib/Interpreter/CIFactory.cpp
@@ -698,6 +698,11 @@ namespace {
                               clingIncLoc.str().str(), MOverlay,
                               /*RegisterModuleMap=*/ true,
                               /*AllowModulemapOverride=*/ false);
+#elif __FreeBSD__ // See 'FreeBSD port maintainer note' in core/clingutils/CMakeLists.txt
+    maybeAppendOverlayEntry(stdIncLoc.str(), "std_fbsd.modulemap",
+                            clingIncLoc.str().str(), MOverlay,
+                            /*RegisterModuleMap=*/ true,
+                            /*AllowModulemapOverride=*/ false);
 #else
     maybeAppendOverlayEntry(cIncLoc.str(), "libc.modulemap",
                             clingIncLoc.str().str(), MOverlay,
