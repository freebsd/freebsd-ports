--- input/input_keymaps.c.orig	2020-08-07 22:06:53 UTC
+++ input/input_keymaps.c
@@ -50,10 +50,8 @@
 #include "SDL.h"
 #endif

-#if defined(__linux__) || defined(__linux__) && defined(HAVE_WAYLAND)
 #include <linux/input.h>
 #include <linux/kd.h>
-#endif

 #ifdef HAVE_X11
 #include "input/include/xfree86_keycodes.h"
