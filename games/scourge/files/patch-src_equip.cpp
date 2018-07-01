--- src/equip.cpp.orig	2008-12-22 23:38:10 UTC
+++ src/equip.cpp
@@ -595,7 +595,7 @@ void Equip::drawCapabilities() {
 		}
 	}
 	if ( !found ) {
-		specialSkill = false;
+		specialSkill = NULL;
 		canvas->setTooltip( "" );
 	}
 	glDisable( GL_BLEND );
