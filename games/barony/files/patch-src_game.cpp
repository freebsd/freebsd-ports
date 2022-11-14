--- src/game.cpp.orig	2022-10-30 17:32:23 UTC
+++ src/game.cpp
@@ -4011,7 +4011,7 @@ int main(int argc, char** argv)
 									}
 
 									real_t limit = PERModifier * 0.01;
-									globalLightModifier = std::min(limit, globalLightModifier + 0.0005);
+									globalLightModifier = std::min(limit, globalLightModifier + (real_t)0.0005);
 
 									int telepathyLimit = std::min(64, 48 + players[clientnum]->entity->getPER());
 									globalLightTelepathyModifier = std::min(telepathyLimit / 255.0, globalLightTelepathyModifier + (0.2 / 255.0));
