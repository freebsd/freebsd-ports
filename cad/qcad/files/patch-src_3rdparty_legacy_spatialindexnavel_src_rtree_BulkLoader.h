--- src/3rdparty/legacy/spatialindexnavel/src/rtree/BulkLoader.h.orig	2026-05-06 14:27:07 UTC
+++ src/3rdparty/legacy/spatialindexnavel/src/rtree/BulkLoader.h
@@ -40,13 +40,13 @@ namespace SpatialIndex
 				Record();
 				Record(const Region& r, id_type id, uint32_t len, byte* pData, uint32_t s);
 				~Record();
-				
+
 				bool operator<(const Record& r) const;
 
 				void storeToFile(Tools::TemporaryFile& f);
 				void loadFromFile(Tools::TemporaryFile& f);
 
-				struct SortAscending : public std::binary_function<Record* const, Record* const, bool>
+				struct SortAscending
 				{
 					bool operator()(Record* const r1, Record* const r2)
 					{
@@ -78,7 +78,7 @@ namespace SpatialIndex
 			public:
 				PQEntry(Record* r, uint32_t u32Index) : m_r(r), m_u32Index(u32Index) {}
 
-				struct SortAscending : public std::binary_function<const PQEntry&, const PQEntry&, bool>
+				struct SortAscending
 				{
 					bool operator()(const PQEntry& e1, const PQEntry& e2)
 					{
