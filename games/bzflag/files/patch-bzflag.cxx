--- src/bzflag/bzflag.cxx.orig	Sat Nov 23 15:16:44 2002
+++ src/bzflag/bzflag.cxx	Sat Nov 23 15:17:53 2002
@@ -756,7 +756,7 @@
 
   // read resources
   {
-    #ifdef __MWERKS__
+    #if 1
 	ifstream resourceStream(getConfigFileName(), ios::in);
      #else
     ifstream resourceStream(getConfigFileName(), ios::in | ios::nocreate);
@@ -768,7 +768,7 @@
 
 #if !defined(_WIN32) & !defined(macintosh)
     else {
-      ifstream resourceStream2(getConfigFileName2(), ios::in | ios::nocreate);
+      ifstream resourceStream2(getConfigFileName2(), ios::in);
       if (resourceStream2) {
 	startupInfo.hasConfiguration = True;
 	resourceStream2 >> db;
