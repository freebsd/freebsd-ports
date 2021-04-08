Fix controls (left acting as right and up as down)

Arith with booleans is a bad idea.

--- src/game/game.c.orig	2021-04-09 17:57:53 UTC
+++ src/game/game.c
@@ -2052,8 +2052,8 @@ void set_one_player_latch( const PLA_REF player )
         if (( CAM_TURN_GOOD == PCamera->turn_mode && 1 == local_numlpla ) ||
             !control_is_pressed( INPUT_DEVICE_KEYBOARD, CONTROL_CAMERA ) )
         {
-            joy_pos.x = ( control_is_pressed( INPUT_DEVICE_KEYBOARD,  CONTROL_RIGHT ) - control_is_pressed( INPUT_DEVICE_KEYBOARD,  CONTROL_LEFT ) );
-            joy_pos.y = ( control_is_pressed( INPUT_DEVICE_KEYBOARD,  CONTROL_DOWN ) - control_is_pressed( INPUT_DEVICE_KEYBOARD,  CONTROL_UP ) );
+            joy_pos.x = ( (int)control_is_pressed( INPUT_DEVICE_KEYBOARD,  CONTROL_RIGHT ) - (int)control_is_pressed( INPUT_DEVICE_KEYBOARD,  CONTROL_LEFT ) );
+            joy_pos.y = ( (int)control_is_pressed( INPUT_DEVICE_KEYBOARD,  CONTROL_DOWN ) - (int)control_is_pressed( INPUT_DEVICE_KEYBOARD,  CONTROL_UP ) );
 
             if ( CAM_TURN_GOOD == PCamera->turn_mode &&
                  1 == local_numlpla )  joy_pos.x = 0;
