--- game/g_items.c.orig	2001-12-22 15:32:24 UTC
+++ game/g_items.c
@@ -40,9 +40,9 @@ gitem_armor_t jacketarmor_info	= { 25,  50, .30, .00, 
 gitem_armor_t combatarmor_info	= { 50, 100, .60, .30, ARMOR_COMBAT};
 gitem_armor_t bodyarmor_info	= {100, 200, .80, .60, ARMOR_BODY};
 
-static int	jacket_armor_index;
-static int	combat_armor_index;
-static int	body_armor_index;
+int	jacket_armor_index;
+int	combat_armor_index;
+int	body_armor_index;
 static int	power_screen_index;
 static int	power_shield_index;
 
