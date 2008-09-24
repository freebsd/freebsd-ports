--- src/video/x11/SDL_x11modes.c.orig
+++ src/video/x11/SDL_x11modes.c
@@ -52,8 +52,25 @@
 #if SDL_VIDEO_DRIVER_X11_VIDMODE
 Bool SDL_NAME(XF86VidModeGetModeInfo)(Display *dpy, int scr, SDL_NAME(XF86VidModeModeInfo) *info)
 {
-    SDL_NAME(XF86VidModeModeLine) *l = (SDL_NAME(XF86VidModeModeLine)*)((char*)info + sizeof info->dotclock);
-    return SDL_NAME(XF86VidModeGetModeLine)(dpy, scr, (int*)&info->dotclock, l);
+    Bool retval;
+    int dotclock;
+    SDL_NAME(XF86VidModeModeLine) l;
+    SDL_memset(&l, 0, sizeof(l));
+    retval = SDL_NAME(XF86VidModeGetModeLine)(dpy, scr, &dotclock, &l);
+    info->dotclock = dotclock;
+    info->hdisplay = l.hdisplay;
+    info->hsyncstart = l.hsyncstart;
+    info->hsyncend = l.hsyncend;
+    info->htotal = l.htotal;
+    info->hskew = l.hskew;
+    info->vdisplay = l.vdisplay;
+    info->vsyncstart = l.vsyncstart;
+    info->vsyncend = l.vsyncend;
+    info->vtotal = l.vtotal;
+    info->flags = l.flags;
+    info->privsize = l.privsize;
+    info->private = l.private;
+    return retval;
 }
 #endif /* SDL_VIDEO_DRIVER_X11_VIDMODE */
 
