--- src/Hazard.cpp.orig	2013-04-01 18:21:13.000000000 +0400
+++ src/Hazard.cpp	2013-09-17 05:59:52.364226200 +0400
@@ -91,17 +91,17 @@
 		activeAnimation->advanceFrame();
 
 	// handle movement
-	if (!(round(speed.x) == 0 && round(speed.y) == 0)) {
+	if (!(myround(speed.x) == 0 && myround(speed.y) == 0)) {
 		pos.x += speed.x;
 		pos.y += speed.y;
 
 		// very simplified collider, could skim around corners
 		// or even pass through thin walls if speed > tilesize
-		if (collider->is_wall(round(pos.x), round(pos.y))) {
+		if (collider->is_wall(myround(pos.x), myround(pos.y))) {
 			lifespan = 0;
 			hit_wall = true;
 
-			if (collider->is_outside_map(round(pos.x) >> TILE_SHIFT, round(pos.y) >> TILE_SHIFT))
+			if (collider->is_outside_map(myround(pos.x) >> TILE_SHIFT, myround(pos.y) >> TILE_SHIFT))
 				remove_now = true;
 		}
 	}
@@ -143,8 +143,8 @@
 {
 	if (delay_frames == 0 && activeAnimation) {
 		Renderable re = activeAnimation->getCurrentFrame(animationKind);
-		re.map_pos.x = round(pos.x);
-		re.map_pos.y = round(pos.y);
+		re.map_pos.x = myround(pos.x);
+		re.map_pos.y = myround(pos.y);
 		(floor ? r_dead : r).push_back(re);
 	}
 }
