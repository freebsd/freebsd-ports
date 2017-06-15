--- src/w_sprite.cc.orig	2010-12-31 04:28:14 UTC
+++ src/w_sprite.cc
@@ -575,7 +575,7 @@ bool W_CheckSpritesExist(const state_gro
 			if (states[i].sprite == SPR_NULL)
 				continue;
 
-			if (sprites[states[i].sprite]->frames > 0)
+			if (sprites[states[i].sprite]->numframes > 0)
 				return true;	
 
 			// -AJA- only check one per group.  It _should_ check them all,
