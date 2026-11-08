--- dlls/winebus.sys/main.c.orig	2026-08-03 08:08:29 UTC
+++ dlls/winebus.sys/main.c
@@ -606,7 +606,7 @@ static BOOL is_hidraw_enabled(WORD vid, WORD pid, cons
 
     if (options.disable_sdl && options.disable_input) prefer_hidraw = TRUE;
     if (is_dualshock4_gamepad(vid, pid)) prefer_hidraw = TRUE;
-    if (is_dualsense_gamepad(vid, pid)) prefer_hidraw = TRUE;
+    if (is_dualsense_gamepad(vid, pid)) prefer_hidraw = FALSE;
 
     switch (vid)
     {
