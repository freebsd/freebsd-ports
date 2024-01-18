--- gemrb/plugins/KEYImporter/KEYImporter.h.orig	2024-01-18 17:19:28 UTC
+++ gemrb/plugins/KEYImporter/KEYImporter.h
@@ -59,7 +59,7 @@ struct MapKeyHash {
 
 struct MapKeyHash {
 	size_t operator()(const MapKey& key) const {
-		size_t h{key.type};
+		uint64_t h{key.type};
 		const char *c = key.ref.c_str();
 
 		for (unsigned int i = 0; *c && i < 9; ++i)
