--- src/3rdparty/legacy/spatialindexnavel/src/spatialindex/MovingRegion.cc.orig	2026-05-06 14:27:07 UTC
+++ src/3rdparty/legacy/spatialindexnavel/src/spatialindex/MovingRegion.cc
@@ -910,7 +910,8 @@ double MovingRegion::getIntersectingAreaInTime(const I
 
 	MovingRegion x = *this;
 	CrossPoint c;
-	std::priority_queue<CrossPoint, std::vector<CrossPoint>, CrossPoint::ascending> pq;
+	auto ascending = [](CrossPoint& lhs, CrossPoint& rhs) { return lhs.m_t > rhs.m_t; };
+	std::priority_queue < CrossPoint, std::vector<CrossPoint>, decltype(ascending)> pq(ascending);
 
 	// find points of intersection in all dimensions.
 	for (uint32_t i = 0; i < m_dimension; ++i)
