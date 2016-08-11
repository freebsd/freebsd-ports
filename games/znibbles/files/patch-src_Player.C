--- src/Player.C.orig	1999-05-11 02:17:08 UTC
+++ src/Player.C
@@ -36,7 +36,7 @@
 #include <string.h>
 #include <time.h>
 
-#include <iostream.h>
+#include <iostream>
 
 #include "Player.H"
 
@@ -78,7 +78,7 @@ void Player::add_description(Trame &t)
 void Player::read_description(Trame &t)
 {
   if (t.get_char() != PLAYER_DESC) {
-    cerr << "Player::read_description(): ohhh le bordel!\n";
+    std::cerr << "Player::read_description(): ohhh le bordel!\n";
     exit(1);
   }
 
@@ -98,10 +98,10 @@ void Player::read_description(Trame &t)
 // debug: print a brief representation of the player
 void Player::display()
 {
-  cout << "   ID:" << id << " Player #" << _number \
+  std::cout << "   ID:" << id << " Player #" << _number \
        << " '" << _name << "' score=" << _score << " frags=" \
        << _frag << " best=" << _best_length << " wid=" \
-       << worm_id<< endl;
+       << worm_id<< std::endl;
 }
 
 
