--- include/common.h.orig	2017-07-14 19:17:29 UTC
+++ include/common.h
@@ -54,7 +54,7 @@ class REPORTER;
 #define GR_KB_LEFTSHIFT  0x20000000                 /* left shift key depressed
                                                      */
 #define GR_KB_CTRL       0x40000000                 // CTRL depressed
-#define GR_KB_ALT        0x80000000                 // ALT depressed
+#define GR_KB_ALT        0x04000000                 // ALT depressed
 #define GR_KB_SHIFT      (GR_KB_LEFTSHIFT | GR_KB_RIGHTSHIFT)
 #define GR_KB_SHIFTCTRL  (GR_KB_SHIFT | GR_KB_CTRL)
 #define MOUSE_MIDDLE     0x08000000                 /* Middle button mouse
