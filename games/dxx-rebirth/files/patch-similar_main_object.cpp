--- similar/main/object.cpp.orig	2019-05-27 09:10:54 UTC
+++ similar/main/object.cpp
@@ -1057,7 +1057,7 @@ static void free_object_slots(uint_fast32_t num_used)
 
 	// Capture before num_to_free modified
 	const auto &&r = partial_const_range(obj_list, num_to_free);
-	auto l = [&vmobjptr, &r, &num_to_free](bool (*predicate)(const vcobjptr_t)) -> bool {
+	auto l = [&r, &num_to_free](bool (*predicate)(const vcobjptr_t)) -> bool {
 		range_for (const auto i, r)
 		{
 			const auto &&o = vmobjptr(i);
@@ -1508,7 +1508,7 @@ static void start_player_death_sequence(object &player
 			auto &proximity = player_info.hoard.orbs;
 			if (proximity < player_info.max_hoard_orbs)
 			{
-				const auto is_bad_kill = [&vmobjptr]{
+				const auto is_bad_kill = []{
 					auto &lplr = get_local_player();
 					auto &lplrobj = get_local_plrobj();
 					const auto killer_objnum = lplrobj.ctype.player_info.killer_objnum;
