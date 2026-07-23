--- cmake/OpenLocoVersion.cmake.orig	2026-05-30 08:07:06 UTC
+++ cmake/OpenLocoVersion.cmake
@@ -50,7 +50,7 @@ else()
 else()
     message(WARNING "Git not found, version information will be limited.")
 
-    set(OPENLOCO_VERSION_TAG "unknown")
+    set(OPENLOCO_VERSION_TAG ${PROJECT_VERSION})
     set(OPENLOCO_BRANCH "unknown")
     set(OPENLOCO_COMMIT_SHA1_SHORT "unknown")
 endif()
