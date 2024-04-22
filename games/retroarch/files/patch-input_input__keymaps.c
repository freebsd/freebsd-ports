--- input/input_keymaps.c.orig	2023-11-06 19:58:13 UTC
+++ input/input_keymaps.c
@@ -54,7 +54,7 @@
 #include "SDL.h"
 #endif
 
-#if defined(__linux__) || defined(HAVE_WAYLAND)
+#if defined(__linux__) || defined(HAVE_WAYLAND) || defined(__FreeBSD__) && !defined(__PS4__)
 #if defined(__linux__)
 #include <linux/input.h>
 #include <linux/kd.h>
@@ -1130,7 +1130,7 @@ const struct rarch_key_map rarch_key_map_x11[] = {
 };
 #endif
 
-#if defined(__linux__) || defined(HAVE_WAYLAND)
+#if defined(__linux__) || defined(HAVE_WAYLAND) || defined(__FreeBSD__) && !defined(__PS4__)
 /* Note: Only one input can be mapped to each
  * RETROK_* key. If several physical inputs
  * correspond to the same key, these inputs
