--- trackercore/player_data.cpp.orig	Mon Mar  4 10:02:51 2002
+++ trackercore/player_data.cpp	Fri Dec 27 21:17:07 2002
@@ -32,7 +32,7 @@
 Player_Data::~Player_Data(){
 }
 
-void Player_Data::set_virtual_channels(int p_amount,bool p_lock = true) {
+void Player_Data::set_virtual_channels(int p_amount,bool p_lock) {
 
 	if (p_amount<1) return;
 	if (p_amount==control.max_voices) return;
