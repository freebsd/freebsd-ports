--- src/map/world.cpp.orig	2022-03-13 19:52:08 UTC
+++ src/map/world.cpp
@@ -147,7 +147,9 @@ std::string world::get_encyclopedia_text() const
 				++supertaxon_counts[rank_supertaxon];
 			}
 
-			for (const auto &[supertaxon, count] : supertaxon_counts) {
+			for (const auto &supertaxon_count : supertaxon_counts) {
+				const auto& supertaxon = supertaxon_count.first;
+				const auto& count = supertaxon_count.second;
 				if (count <= 1) {
 					continue;
 				}
