--- mysql-query-browser/source/linux/MQBookmarkBrowser.cc.orig	Sat Apr  8 21:26:35 2006
+++ mysql-query-browser/source/linux/MQBookmarkBrowser.cc	Sat Apr  8 21:27:52 2006
@@ -257,7 +257,8 @@
   {
     for (unsigned int i=0; i < _menu.items().size(); i++)
       _menu.items()[i].set_sensitive(false);
-    _menu.items()[3].set_sensitive(true); // New Folder
+    if( _menu.items().size() > 3 )
+      _menu.items()[3].set_sensitive(true); // New Folder
   }
 }
 
