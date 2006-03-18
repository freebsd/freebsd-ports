# 1.24
Index: qemu/sdl.c
@@ -404,6 +404,7 @@
                 mod_state = (ev->key.keysym.mod & gui_grab_code);
                 if (!mod_state) {
                     if (gui_key_modifier_pressed) {
+                        gui_key_modifier_pressed = 0;
                         if (gui_keysym == 0) {
                             /* exit/enter grab if pressing Ctrl-Alt */
                             if (!gui_grab)
@@ -415,7 +416,6 @@
                             reset_keys();
                             break;
                         }
-                        gui_key_modifier_pressed = 0;
                         gui_keysym = 0;
                     }
                 }
@@ -456,8 +456,8 @@
             }
             break;
         case SDL_ACTIVEEVENT:
-            if (gui_grab && (ev->active.gain & SDL_ACTIVEEVENTMASK) == 0 &&
-                !gui_fullscreen_initial_grab) {
+            if (gui_grab && ev->active.state == SDL_APPINPUTFOCUS &&
+                !ev->active.gain && !gui_fullscreen_initial_grab) {
                 sdl_grab_end();
             }
             break;
