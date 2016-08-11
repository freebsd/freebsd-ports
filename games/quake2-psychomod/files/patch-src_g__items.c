--- src/g_items.c.orig	2016-06-20 14:35:21 UTC
+++ src/g_items.c
@@ -21,9 +21,9 @@ gitem_armor_t jacketarmor_info	= { 25,  
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
 
