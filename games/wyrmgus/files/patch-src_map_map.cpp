--- src/map/map.cpp.orig	2021-11-17 14:34:51 UTC
+++ src/map/map.cpp
@@ -3759,6 +3759,7 @@ void CMap::clear_paths_between_subtemplates(const int 
 	const CMapLayer *map_layer = this->MapLayers[z].get();
 
 	for (const auto &[subtemplate, subtemplate_rect] : map_layer->subtemplate_areas) {
+		const auto& subtemplate_ = subtemplate;
 		const QPoint min_pos = subtemplate_rect.topLeft();
 		const QPoint max_pos = subtemplate_rect.bottomRight();
 
@@ -3788,7 +3789,7 @@ void CMap::clear_paths_between_subtemplates(const int 
 				return;
 			}
 
-			subtemplate_path_start_points[subtemplate].push_back(std::move(adjacent_pos));
+			subtemplate_path_start_points[subtemplate_].push_back(std::move(adjacent_pos));
 		});
 	}
 
