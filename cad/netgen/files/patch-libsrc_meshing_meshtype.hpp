--- libsrc/meshing/meshtype.hpp.orig	Sun Nov  7 17:12:10 2004
+++ libsrc/meshing/meshtype.hpp	Tue May 29 18:43:39 2007
@@ -962,7 +962,7 @@
 class Identifications
 {
 private:
-  Mesh & mesh;
+  class Mesh & mesh;
 
   /// identify points (thin layers, periodic b.c.)  
   INDEX_2_HASHTABLE<int> * identifiedpoints;
