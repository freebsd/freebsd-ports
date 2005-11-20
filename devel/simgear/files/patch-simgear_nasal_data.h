--- simgear/nasal/data.h.orig	Sun Nov 20 22:30:00 2005
+++ simgear/nasal/data.h	Sun Nov 20 22:30:14 2005
@@ -47,7 +47,7 @@
 struct VecRec {
     int size;
     int alloced;
-    naRef array[];
+    naRef array[0];
 };
 
 struct naVec {
@@ -66,7 +66,7 @@
     int dels;
     int lgalloced;
     struct HashNode* nodes;
-    struct HashNode* table[];
+    struct HashNode* table[0];
 };
 
 struct naHash {
