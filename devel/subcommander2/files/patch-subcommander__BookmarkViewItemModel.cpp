--- subcommander/BookmarkViewItemModel.cpp.orig	2009-09-20 18:24:16.000000000 +0900
+++ subcommander/BookmarkViewItemModel.cpp	2012-05-10 05:38:50.000000000 +0900
@@ -219,7 +219,8 @@
     if( !advance )
       return false;
 
-    _frame = ++_frame % ActiveDecorationFrames;
+    ++_frame;
+    _frame = _frame % ActiveDecorationFrames;
     return true;
   }
 
