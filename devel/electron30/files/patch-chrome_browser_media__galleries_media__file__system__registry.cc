--- chrome/browser/media_galleries/media_file_system_registry.cc.orig	2024-02-21 00:20:34 UTC
+++ chrome/browser/media_galleries/media_file_system_registry.cc
@@ -584,7 +584,12 @@ MediaFileSystemRegistry::MediaFileSystemRegistry()
 // Constructor in 'private' section because depends on private class definition.
 MediaFileSystemRegistry::MediaFileSystemRegistry()
     : file_system_context_(new MediaFileSystemContextImpl) {
-  StorageMonitor::GetInstance()->AddObserver(this);
+  /*
+   * This conditional is needed for shutdown.  Destructors
+   * try to get the media file system registry.
+   */
+  if (StorageMonitor::GetInstance())
+    StorageMonitor::GetInstance()->AddObserver(this);
 }
 
 MediaFileSystemRegistry::~MediaFileSystemRegistry() {
