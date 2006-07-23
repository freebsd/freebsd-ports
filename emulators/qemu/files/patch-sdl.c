Index: qemu/sdl.c
@@ -280,13 +280,19 @@
 
 static void sdl_hide_cursor(void)
 {
-    SDL_SetCursor(sdl_cursor_hidden);
+    if (kbd_mouse_is_absolute()) {
+       SDL_ShowCursor(1);
+       SDL_SetCursor(sdl_cursor_hidden);
+    } else {
+       SDL_ShowCursor(0);
+    }
+
 }
 
 static void sdl_show_cursor(void)
 {
     if (!kbd_mouse_is_absolute()) {
-	SDL_SetCursor(sdl_cursor_normal);
+       SDL_ShowCursor(1);
     }
 }
 
