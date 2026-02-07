--- src/libraries/Box2D/Collision/Shapes/b2ChainShape.h.orig	2012-04-06 18:15:01 UTC
+++ src/libraries/Box2D/Collision/Shapes/b2ChainShape.h
@@ -95,8 +95,8 @@ inline b2ChainShape::b2ChainShape()
 	m_radius = b2_polygonRadius;
 	m_vertices = NULL;
 	m_count = 0;
-	m_hasPrevVertex = NULL;
-	m_hasNextVertex = NULL;
+	m_hasPrevVertex = false;
+	m_hasNextVertex = false;
 }
 
 #endif
