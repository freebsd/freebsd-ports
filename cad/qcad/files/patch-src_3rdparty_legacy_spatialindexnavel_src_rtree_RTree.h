--- src/3rdparty/legacy/spatialindexnavel/src/rtree/RTree.h.orig	2026-05-06 14:27:07 UTC
+++ src/3rdparty/legacy/spatialindexnavel/src/rtree/RTree.h
@@ -157,10 +157,6 @@ namespace SpatialIndex
 				NNEntry(id_type id, IEntry* e, double f) : m_id(id), m_pEntry(e), m_minDist(f) {}
 				~NNEntry() {}
 
-				struct ascending : public std::binary_function<NNEntry*, NNEntry*, bool>
-				{
-					bool operator()(const NNEntry* __x, const NNEntry* __y) const { return __x->m_minDist > __y->m_minDist; }
-				};
 			}; // NNEntry
 
 			class NNComparator : public INearestNeighborComparator
