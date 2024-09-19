--- interpreter/cling/lib/Interpreter/CIFactory.cpp.orig	2024-06-24 15:02:26 UTC
+++ interpreter/cling/lib/Interpreter/CIFactory.cpp
@@ -699,6 +699,25 @@ namespace {
                               clingIncLoc.str().str(), MOverlay,
                               /*RegisterModuleMap=*/ true,
                               /*AllowModulemapOverride=*/ false);
+#elif __FreeBSD__
+    auto fvMajor = Triple.getOSVersion().getMajor();
+    auto fvMinor = Triple.getOSVersion().getMinor();
+    // Same issue on FreeBSD 13.3+, 14.1+ and 15+ as introduced in MacOS sdk 15.3 ('core/clingutils/CMakeLists.txt')
+    if ((fvMajor == 13 && fvMinor >= 3) || (fvMajor == 14 && fvMinor >= 1) || fvMajor >= 15) {
+        maybeAppendOverlayEntry(stdIncLoc.str(), "std_darwin.modulemap",
+                                clingIncLoc.str().str(), MOverlay,
+                                /*RegisterModuleMap=*/ true,
+                                /*AllowModulemapOverride=*/ false);
+    } else {
+        maybeAppendOverlayEntry(stdIncLoc.str(), "std.modulemap",
+                                clingIncLoc.str().str(), MOverlay,
+                                /*RegisterModuleMap=*/ true,
+                                /*AllowModulemapOverride=*/true);
+    }
+    maybeAppendOverlayEntry(cIncLoc.str(), "libc.modulemap",
+                            clingIncLoc.str().str(), MOverlay,
+                            /*RegisterModuleMap=*/ true,
+                            /*AllowModulemapOverride=*/true);
 #else
     maybeAppendOverlayEntry(cIncLoc.str(), "libc.modulemap",
                             clingIncLoc.str().str(), MOverlay,
