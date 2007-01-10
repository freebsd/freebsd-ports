--- ./g_items.c.orig	Wed Mar  4 18:51:16 1998
+++ ./g_items.c	Wed Jan 10 19:04:52 2007
@@ -21,9 +21,9 @@
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
 
