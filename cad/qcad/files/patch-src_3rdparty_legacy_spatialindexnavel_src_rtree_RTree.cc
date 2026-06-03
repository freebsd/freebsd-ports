--- src/3rdparty/legacy/spatialindexnavel/src/rtree/RTree.cc.orig	2026-05-06 14:27:07 UTC
+++ src/3rdparty/legacy/spatialindexnavel/src/rtree/RTree.cc
@@ -525,7 +525,8 @@ void SpatialIndex::RTree::RTree::nearestNeighborQuery(
 	Tools::LockGuard lock(&m_lock);
 #endif
 
-	std::priority_queue<NNEntry*, std::vector<NNEntry*>, NNEntry::ascending> queue;
+	auto ascending = [](const NNEntry* lhs, const NNEntry* rhs) { return rhs->m_minDist > lhs->m_minDist; };
+	std::priority_queue<NNEntry*, std::vector<NNEntry*>, decltype(ascending)> queue(ascending);
 
 	queue.push(new NNEntry(m_rootID, 0, 0.0));
 
