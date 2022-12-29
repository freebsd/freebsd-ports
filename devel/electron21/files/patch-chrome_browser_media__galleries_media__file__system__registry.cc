--- chrome/browser/media_galleries/media_file_system_registry.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/media_galleries/media_file_system_registry.cc
@@ -744,7 +744,12 @@ class MediaFileSystemRegistry::MediaFileSystemContextI
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
