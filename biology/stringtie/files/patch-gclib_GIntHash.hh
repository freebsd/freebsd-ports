--- gclib/GIntHash.hh.orig	2018-03-06 16:29:49 UTC
+++ gclib/GIntHash.hh
@@ -122,7 +122,7 @@ public:
   uint32 NextKey() {
      Cell* cell=ghash.NextCell();
      if (cell) return cell->key;
-       else return NULL;
+       else return 0;
   }
   OBJ* NextValue() {
      Cell* cell=ghash.NextCell();
@@ -201,7 +201,7 @@ public:
   uint32 NextKey() {
      Cell* cell=ghash.NextCell();
      if (cell) return cell->key;
-       else return NULL;
+       else return 0;
   }
   OBJ* NextValue() {
      Cell* cell=ghash.NextCell();
