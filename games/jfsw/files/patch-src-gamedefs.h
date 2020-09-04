Avoid buffer overflow @src/config.c:255 where JoystickDigitalAxes[6] overrides
RTSName.

--- src/gamedefs.h.orig	2020-09-03 06:19:21 UTC
+++ src/gamedefs.h
@@ -125,7 +125,7 @@ extern "C" {
 
 // Number of JOY axes
 
-#define MAXJOYAXES 6
+#define MAXJOYAXES 12
 
 // Number of GAMEPAD axes
 
