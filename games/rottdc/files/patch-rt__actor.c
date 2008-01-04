--- rt_actor.c.bak	Tue Jan  7 03:31:51 2003
+++ rt_actor.c	Fri Jan  4 19:07:08 2008
@@ -430,7 +430,7 @@
 void AvoidPlayerMissile(objtype*ob);
 int EnvironmentDamage(objtype *ob);
 
-static int     STOPSPEED         =    0x200;
+int     STOPSPEED         =    0x200;
 static int     PLAYERFRICTION    =    0xe000;
 static int     ACTORFRICTION     =    0xf000;
 static int     DIAGADJUST        =    0xb504;
