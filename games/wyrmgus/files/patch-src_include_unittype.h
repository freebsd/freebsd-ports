--- src/include/unittype.h.orig	2015-11-10 20:52:37 UTC
+++ src/include/unittype.h
@@ -59,6 +59,7 @@
 #include <vector>
 #include <algorithm>
 #include <map>
+#include <cstring>
 
 /*----------------------------------------------------------------------------
 --  Declarations
@@ -132,9 +133,9 @@ public:
 		FrameWidth(0), FrameHeight(0),
 		Animations(NULL), Construction(NULL), Sprite(NULL), ShadowSprite(NULL), LeftArmSprite(NULL), RightArmSprite(NULL), HairSprite(NULL), ClothingSprite(NULL), ClothingLeftArmSprite(NULL), ClothingRightArmSprite(NULL), PantsSprite(NULL), ShoesSprite(NULL), WeaponSprite(NULL), ShieldSprite(NULL), HelmetSprite(NULL)
 	{
-		memset(SpriteWhenLoaded, NULL, sizeof(SpriteWhenLoaded));		
-		memset(SpriteWhenEmpty, NULL, sizeof(SpriteWhenEmpty));	
-		memset(ShieldAnimation, NULL, sizeof(ShieldAnimation));
+		memset(SpriteWhenLoaded, 0, sizeof(SpriteWhenLoaded));	
+		memset(SpriteWhenEmpty, 0, sizeof(SpriteWhenEmpty));
+		memset(ShieldAnimation, 0, sizeof(ShieldAnimation));
 	}
 	
 	~VariationInfo();
