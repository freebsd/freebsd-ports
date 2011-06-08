--- m_misc.c.ori	Sun Mar  4 15:50:54 2007
+++ m_misc.c	Sun Mar  4 15:52:40 2007
@@ -365,6 +365,7 @@
 extern	long	key_right, key_left, key_up, key_down;
 extern	long	key_strafeleft, key_straferight;
 extern	long	key_fire, key_use, key_strafe, key_speed;
+extern  long    key_health, key_tomeofpower, key_egg, key_firebomb;
 extern	long	key_flyup, key_flydown, key_flycenter;
 extern	long	key_lookup, key_lookdown, key_lookcenter;
 extern	long	key_invleft, key_invright, key_useartifact;
@@ -447,6 +448,10 @@
 
   { "key_fire", &key_fire, KEY_RCTRL, 1 }, 
   { "key_use", &key_use, ' ', 1 }, 
+  { "key_health", &key_health, 'a' },
+  { "key_tomeofpower", &key_tomeofpower, 127},
+  { "key_egg", &key_egg, 'q'},
+  { "key_firebomb", &key_firebomb, 'b'},
   { "key_strafe", &key_strafe, KEY_RALT, 1 }, 
   { "key_speed", &key_speed, KEY_RSHIFT, 1 },
   
