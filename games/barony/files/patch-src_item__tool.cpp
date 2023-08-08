--- src/item_tool.cpp.orig	2022-10-30 18:55:30 UTC
+++ src/item_tool.cpp
@@ -923,7 +923,7 @@ void Item::applyBomb(Entity* parent, ItemType type, It
 			entity->flags[UPDATENEEDED] = true;
 			entity->x = thrown->x;
 			entity->y = thrown->y;
-			entity->z = std::min(4.0, thrown->z);
+			entity->z = std::min((real_t)4.0, thrown->z);
 			int height = 1;
 			switch ( dir )
 			{
@@ -1046,10 +1046,10 @@ void Item::applyBomb(Entity* parent, ItemType type, It
 			entity->flags[UPDATENEEDED] = true;
 			entity->x = thrown->x;
 			entity->y = thrown->y;
-			entity->z = std::min(4.0, thrown->z);
+			entity->z = std::min((real_t)4.0, thrown->z);
 			if ( placement == BOMB_CHEST )
 			{
-				entity->z = std::max(2.0, entity->z);
+				entity->z = std::max((real_t)2.0, entity->z);
 			}
 
 			if ( hit.side == 0 )
@@ -1334,4 +1334,4 @@ bool itemIsThrowableTinkerTool(const Item* item)
 		return true;
 	}
 	return false;
-}
\ No newline at end of file
+}
