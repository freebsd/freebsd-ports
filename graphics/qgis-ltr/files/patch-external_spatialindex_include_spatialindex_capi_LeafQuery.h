--- external/spatialindex/include/spatialindex/capi/LeafQuery.h.orig	2026-07-31 12:35:21 UTC
+++ external/spatialindex/include/spatialindex/capi/LeafQuery.h
@@ -40,7 +40,7 @@ class SIDX_DLL LeafQuery : public SpatialIndex::IQuery
 public:
 
 	LeafQuery();
-	~LeafQuery() { }
+	~LeafQuery();
 	void getNextEntry(	const SpatialIndex::IEntry& entry, 
 						SpatialIndex::id_type& nextEntry, 
 						bool& hasNext);
