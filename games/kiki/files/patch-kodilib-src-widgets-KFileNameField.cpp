--- kodilib/src/widgets/KFileNameField.cpp.orig	2003-04-14 01:53:22.000000000 +0400
+++ kodilib/src/widgets/KFileNameField.cpp	2013-12-24 04:54:19.830560677 +0400
@@ -41,7 +41,7 @@
         std::string restPath; 				 // path behind cursor
         
         // map cropped path to current directory and rest path to file prefix
-        unsigned int lastSlashPos = croppedPath.rfind("/");
+        size_t lastSlashPos = croppedPath.rfind("/");
         if (lastSlashPos < croppedPath.size()-1)
         {
             restPath = croppedPath.substr(lastSlashPos+1);
