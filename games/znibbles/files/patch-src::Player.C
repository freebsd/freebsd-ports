--- src/Player.C	Tue May 11 12:17:08 1999
+++ src/Player.C	Sat Oct 26 00:41:14 2002
@@ -36,7 +36,7 @@
 #include <string.h>
 #include <time.h>
 
-#include <iostream.h>
+#include <iostream>
 
 #include "Player.H"
 
@@ -78,7 +78,7 @@
 void Player::read_description(Trame &t)
 {
   if (t.get_char() != PLAYER_DESC) {
-    cerr << "Player::read_description(): ohhh le bordel!\n";
+    std::cerr << "Player::read_description(): ohhh le bordel!\n";
     exit(1);
   }
 
@@ -98,10 +98,10 @@
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
 
 
