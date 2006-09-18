--- src/gvcore/fileopobject.cpp.orig	Mon Sep 18 03:19:50 2006
+++ src/gvcore/fileopobject.cpp	Mon Sep 18 03:20:10 2006
@@ -229,7 +229,7 @@
 		if (!dlg.exec()) return;
 		shouldDelete = dlg.shouldDelete();
 	} else {
-		shouldDelete = not FileOperationConfig::deleteToTrash();
+		shouldDelete = !FileOperationConfig::deleteToTrash();
 	}
 		
 
