--- include/common.h.orig	2015-04-19 12:57:35.742686441 +0000
+++ include/common.h	2015-04-19 13:01:10.154899960 +0000
@@ -56,5 +56,5 @@
                                                      */
 #define GR_KB_CTRL       0x40000000                 // CTRL depressed
-#define GR_KB_ALT        0x80000000                 // ALT depressed
+#define GR_KB_ALT        0x04000000                 // ALT depressed
 #define GR_KB_SHIFT      (GR_KB_LEFTSHIFT | GR_KB_RIGHTSHIFT)
 #define GR_KB_SHIFTCTRL  (GR_KB_SHIFT | GR_KB_CTRL)
