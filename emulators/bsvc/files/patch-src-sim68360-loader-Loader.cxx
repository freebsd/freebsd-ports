--- sim68360/loader/Loader.cxx.orig	Sun Nov  3 12:25:40 2002
+++ sim68360/loader/Loader.cxx	Sun Nov  3 12:25:52 2002
@@ -26,7 +26,7 @@
   string error;
 
   // Open the file for reading
-  #ifdef WIN32
+  #ifdef USE_STD
     fstream file(filename, ios::in);
   #else
     fstream file(filename, ios::in | ios::nocreate);
