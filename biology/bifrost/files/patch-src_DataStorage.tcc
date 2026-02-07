--- src/DataStorage.tcc.orig	2024-03-15 15:20:17 UTC
+++ src/DataStorage.tcc
@@ -78,7 +78,10 @@ DataStorage<U>::DataStorage(const DataStorage& o) : co
 
         unitig_cs_link = new atomic<uint64_t>[sz_link];
 
-        for (size_t i = 0; i != sz_link; ++i) unitig_cs_link[i] = o.sz_link[i].load();
+	// Hayzam Sherif: o.sz_link -> o.unitig_cs_link
+	// Independently proposed by Lucas van Dijk:
+	// https://github.com/pmelsted/bifrost/pull/18/files
+        for (size_t i = 0; i != sz_link; ++i) unitig_cs_link[i] = o.unitig_cs_link[i].load();
     }
 
     if ((o.data != nullptr) && (o.sz_cs != 0)){
