--- cfg_control.h.orig	2006-02-09 21:21:23 UTC
+++ cfg_control.h
@@ -29,7 +29,7 @@
 #define NUM_KEYB_CONTROLS  2
 
 /* constant assignment of control to event type */
-const XBEventCode keyEventType[NUM_KEYB_CONTROLS];
+extern const XBEventCode keyEventType[NUM_KEYB_CONTROLS];
 
 /* ingame controls for editing*/
 typedef struct
