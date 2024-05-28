--- src/MetaPopInfo.cc.orig	2024-05-28 12:36:52 UTC
+++ src/MetaPopInfo.cc
@@ -423,7 +423,7 @@ void MetaPopInfo::fill_pop_indexes(map<int, pair<int, 
 
 void MetaPopInfo::fill_pop_indexes(map<int, pair<int, int> >& pop_indexes) const {
     pop_indexes.clear();
-    for (size_t i = 0; i < pops_.size(); ++i)
+    for (int i = 0; i < pops_.size(); ++i)
         pop_indexes.insert( {i, {pops_[i].first_sample, pops_[i].last_sample}} );
 }
 
