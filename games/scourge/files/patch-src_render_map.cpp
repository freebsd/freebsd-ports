--- src/render/map.cpp.orig	2008-12-22 23:38:10 UTC
+++ src/render/map.cpp
@@ -3154,7 +3154,7 @@ Shape *Map::isWallBetween( int x1, int y
 			if ( shape )
 				return shape;
 		}
-		return false;
+		return NULL;
 	}
 	if ( y1 == y2 ) {
 		if ( x1 > x2 ) SWAP( x1, x2 );
@@ -3163,7 +3163,7 @@ Shape *Map::isWallBetween( int x1, int y
 			if ( shape )
 				return shape;
 		}
-		return false;
+		return NULL;
 	}
 
 
@@ -4599,7 +4599,7 @@ Location *MapMemoryManager::newLocation(
 	pos->item = NULL;
 	pos->creature = NULL;
 	pos->outlineColor = NULL;
-	pos->texIndex = NULL;
+	pos->texIndex = 0;
 
 	return pos;
 }
