--- src/bzflag/bzflag.cxx.orig	Fri Dec  6 02:22:44 2002
+++ src/bzflag/bzflag.cxx	Mon Dec  9 22:09:36 2002
@@ -769,7 +769,7 @@
 
   // read resources
   {
-    #ifdef __MWERKS__
+    #if 1
 	ifstream resourceStream(getConfigFileName(), ios::in);
      #else
     ifstream resourceStream(getConfigFileName(), ios::in);
