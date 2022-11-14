--- src/acthudweapon.cpp.orig	2022-10-30 17:42:45 UTC
+++ src/acthudweapon.cpp
@@ -2381,9 +2381,9 @@ void actHudWeapon(Entity* my)
 	}
 	else if ( HUDWEAPON_CHOP == 10 ) // special punch
 	{
-		HUDWEAPON_MOVEX = std::max(static_cast<real_t>(0.0), HUDWEAPON_MOVEX - .15); // forward/back
-		HUDWEAPON_MOVEY = std::min(static_cast<real_t>(1.0), HUDWEAPON_MOVEY + .25); // left/right
-		HUDWEAPON_MOVEZ = std::max(static_cast<real_t>(-2.0), HUDWEAPON_MOVEZ - .05); // up/down
+		HUDWEAPON_MOVEX = std::max(static_cast<real_t>(0.0), static_cast<real_t>(HUDWEAPON_MOVEX - .15)); // forward/back
+		HUDWEAPON_MOVEY = std::min(static_cast<real_t>(1.0), static_cast<real_t>(HUDWEAPON_MOVEY + .25)); // left/right
+		HUDWEAPON_MOVEZ = std::max(static_cast<real_t>(-2.0), static_cast<real_t>(HUDWEAPON_MOVEZ - .05)); // up/down
 
 		HUDWEAPON_YAW -= .15;
 		if ( HUDWEAPON_YAW < 2 * PI / 5 )
@@ -4120,4 +4120,4 @@ void actHudArrowModel(Entity* my)
 	my->scalex = hudweapon->scalex;
 	my->scaley = hudweapon->scaley;
 	my->scalez = hudweapon->scalez;
-}
\ No newline at end of file
+}
