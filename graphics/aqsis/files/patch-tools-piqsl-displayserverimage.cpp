--- tools/piqsl/displayserverimage.cpp.orig	2012-02-20 18:42:02.000000000 +0300
+++ tools/piqsl/displayserverimage.cpp	2012-02-20 18:42:18.000000000 +0300
@@ -98,8 +98,8 @@
 		++index;
 	}
 
-	setFilename(uniquePath.file_string());
-	saveToFile(uniquePath.file_string());
+	setFilename(uniquePath.string());
+	saveToFile(uniquePath.string());
 }
 
 
