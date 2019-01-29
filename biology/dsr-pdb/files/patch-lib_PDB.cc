--- lib/PDB.cc.orig	2019-01-29 06:57:50 UTC
+++ lib/PDB.cc
@@ -82,7 +82,7 @@ namespace dsrpdb {
     assert(i < models_.size());
     return models_[i];
   };
-  unsigned int PDB::number_of_models() const {
+  size_t PDB::number_of_models() const {
     return models_.size(); 
   }
 
