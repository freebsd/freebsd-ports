--- src/game_display.cpp.orig	2025-12-01 17:11:07 UTC
+++ src/game_display.cpp
@@ -278,9 +278,9 @@ void game_display::draw_hex(const map_location& loc)
 	// Draw reach_map information.
 	// We remove the reachability mask of the unit that we want to attack.
 	if(!is_shrouded && !reach_map_.empty() && reach_map_.find(loc) == reach_map_.end() && loc != attack_indicator_dst_) {
-		static const image::locator unreachable(game_config::images::unreachable);
+		static const image::locator unreachable_image(game_config::images::unreachable);
 		drawing_buffer_add(LAYER_REACHMAP, loc,
-			[tex = image::get_texture(unreachable, image::HEXED)](const rect& dest) { draw::blit(tex, dest); });
+			[tex = image::get_texture(unreachable_image, image::HEXED)](const rect& dest) { draw::blit(tex, dest); });
 	}
 
 	if(std::shared_ptr<wb::manager> w = wb_.lock()) {
