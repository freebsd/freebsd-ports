--- src/3rdparty/legacy/spatialindexnavel/include/spatialindex/MovingRegion.h.orig	2026-05-06 14:27:07 UTC
+++ src/3rdparty/legacy/spatialindexnavel/include/spatialindex/MovingRegion.h
@@ -152,10 +152,6 @@ namespace SpatialIndex
 			uint32_t m_boundary;
 			const MovingRegion* m_to;
 
-			struct ascending: public std::binary_function<CrossPoint&, CrossPoint&, bool>
-			{
-				bool operator()(const CrossPoint& __x, const CrossPoint& __y) const { return __x.m_t > __y.m_t; }
-			};
 		}; // CrossPoint
 
 	public:
