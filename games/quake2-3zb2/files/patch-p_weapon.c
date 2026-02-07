--- ./p_weapon.c.orig	Sat Dec 30 19:09:03 2006
+++ ./p_weapon.c	Sat Dec 30 19:09:23 2006
@@ -4,7 +4,7 @@
 #include "m_player.h"
 #include "bot.h"
 
-static qboolean	is_quad;
+qboolean	is_quad;
 // RAFAEL
 static qboolean is_quadfire;
 static byte		is_silenced;
@@ -2140,7 +2140,7 @@
 	vec3_t		forward, right, up;
 	vec3_t		offset;
 	vec3_t		v;
-	int			kick = 12;
+//	int			kick = 12;
 	int			damage;
 	float		damage_radius;
 	int			radius_damage;
