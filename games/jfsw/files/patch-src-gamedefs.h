Avoid buffer overflow @src/config.c:255 where JoystickDigitalAxes[6] overrides
RTSName.

--- src/gamedefs.h.orig	2014-11-19 08:03:04.589718681 +0100
+++ src/gamedefs.h	2014-11-19 08:03:37.128424065 +0100
@@ -125,7 +125,7 @@
 
 // Number of JOY axes
 
-#define MAXJOYAXES 6
+#define MAXJOYAXES 12
 
 // Number of GAMEPAD axes
 
