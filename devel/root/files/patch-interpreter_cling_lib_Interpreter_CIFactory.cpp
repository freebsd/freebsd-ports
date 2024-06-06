--- interpreter/cling/lib/Interpreter/CIFactory.cpp.orig	2024-05-30 18:22:02 UTC
+++ interpreter/cling/lib/Interpreter/CIFactory.cpp
@@ -699,6 +699,11 @@ namespace {
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
