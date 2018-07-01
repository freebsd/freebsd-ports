--- src/rpg/character.h.orig	2008-12-22 23:38:10 UTC
+++ src/rpg/character.h
@@ -63,7 +63,7 @@ public:
 	static int getRootCount() {
 		if ( instance == NULL ) { 
 			std::cerr << "*** Characters::getRootCount() Characters uninitialized" << std::endl;
-			return NULL;
+			return 0;
 		}
 		return instance->rootCharacters.size();
 	}
