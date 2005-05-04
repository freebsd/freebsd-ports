--- src/i_sdlvideo.c.orig	Tue Dec  4 17:08:44 2001
+++ src/i_sdlvideo.c	Tue Sep 21 22:27:07 2004
@@ -32,6 +32,7 @@
 
 int mouse_scale_factor;
 int save_buttons;
+int grab_input;
 
 extern int usemouse;
 
@@ -460,7 +461,13 @@
 success:
  if (WMAvailable) {
   SDL_WM_SetCaption("U-Hexen 0.6",NULL);
-  SDL_WM_GrabInput(SDL_GRAB_ON);
+  if(M_CheckParm("-nograb")) {
+    grab_input = 0;
+  }
+  else {
+   grab_input = 1;
+   SDL_WM_GrabInput(SDL_GRAB_ON);
+  }
  }
  SDL_WarpMouse(SDLWidth/2,SDLHeight/2);
  SDL_ShowCursor(SDL_DISABLE);
@@ -470,7 +477,7 @@
 void VSDL_ShutdownGraphics(void)
 {
  if (WMAvailable) {
-  SDL_WM_GrabInput(SDL_GRAB_OFF);
+  if(grab_input == 1) SDL_WM_GrabInput(SDL_GRAB_OFF);
  } 
 }
 
@@ -599,7 +606,7 @@
   if (Event.motion.x==SDLWidth/2 && Event.motion.y==SDLHeight/2) break;
   if ((event.data2=(Event.motion.xrel)*mouse_scale_factor) ||
       (event.data3=(-Event.motion.yrel)*mouse_scale_factor)) {
-    SDL_WarpMouse(SDLWidth/2,SDLHeight/2);
+    if(grab_input == 1) SDL_WarpMouse(SDLWidth/2,SDLHeight/2);
     event.type=ev_mouse;
     H2_PostEvent(&event);
   }
