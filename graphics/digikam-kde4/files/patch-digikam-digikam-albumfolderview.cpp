--- digikam/digikam/albumfolderview.cpp.orig	Thu Nov 25 12:19:57 2004
+++ digikam/digikam/albumfolderview.cpp	Thu Nov 25 12:20:46 2004
@@ -836,7 +836,7 @@
     folderItem->setPixmap(thumbnail);
 }
 
-void::AlbumFolderView::slotThumbnailLost(const KURL &url, bool isDir)
+void AlbumFolderView::slotThumbnailLost(const KURL &url, bool isDir)
 {
     if(isDir)
         return;
