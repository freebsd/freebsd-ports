--- src/game.cpp.orig	2015-03-09 05:25:34 UTC
+++ src/game.cpp
@@ -9545,7 +9545,7 @@ int game::list_items(const int iLastStat
             if (ground_items.empty() && iLastState == 1) {
                 reset_item_list_state(w_items_border, iInfoHeight, bRadiusSort);
                 wrefresh(w_items_border);
-                mvwprintz(w_items, 10, 2, c_white, _("You dont see any items around you!"));
+                mvwprintz(w_items, 10, 2, c_white, _("You don't see any items around you!"));
             } else {
                 werase(w_items);
 
@@ -9808,7 +9808,7 @@ int game::list_monsters(const int iLastS
 
             if (vMonsters.empty()) {
                 wrefresh(w_monsters_border);
-                mvwprintz(w_monsters, 10, 2, c_white, _("You dont see any monsters around you!"));
+                mvwprintz(w_monsters, 10, 2, c_white, _("You don't see any monsters around you!"));
             } else {
                 if( static_cast<size_t>( iActive ) >= vMonsters.size() ) {
                     iActive = 0;
