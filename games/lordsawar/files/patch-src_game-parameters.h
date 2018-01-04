--- src/game-parameters.h.orig	2015-06-10 17:55:57 UTC
+++ src/game-parameters.h
@@ -117,6 +117,7 @@ public:
         return 8;
       else if (param == GameParameters::Player::OFF)
         return 0; //no equiv.
+	  return 0;
     }
   static GameParameters::Player::Type player_param_string_to_player_param(Glib::ustring s)
     {
