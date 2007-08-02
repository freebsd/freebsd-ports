--- src/backend/album.h.orig	Wed Jul 25 21:29:36 2007
+++ src/backend/album.h	Wed Jul 25 21:29:43 2007
@@ -113,7 +113,7 @@
   int getCreationDay();
 
   ///Updates the creation date to today's date
-  void Album::updateCreationDate();
+  void updateCreationDate();
 
   ///Updates the modification date to today's date
   void updateModificationDate();
