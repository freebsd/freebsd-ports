--- src/emu.c.orig	2003-07-11 13:43:26 UTC
+++ src/emu.c
@@ -54,6 +54,8 @@ Uint8 jmap[8]={1,1,0,0,3,2,0,1};
 Sint16 *joy_axis;
 Uint8 *joy_but;
 
+GNGB_CONF conf;
+
 /* Configuration File */
 
 #define UINTEGER8  1
