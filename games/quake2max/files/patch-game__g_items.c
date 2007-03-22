--- game/g_items.c.orig	Sat Dec 22 12:32:24 2001
+++ game/g_items.c	Thu Mar 22 00:34:42 2007
@@ -40,9 +40,9 @@
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
 
