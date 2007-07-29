--- ui/svga/svgakeyboard.c.orig	2007-07-29 14:59:10.000000000 +0200
+++ ui/svga/svgakeyboard.c	2007-07-29 15:10:19.000000000 +0200
@@ -75,7 +75,8 @@
   if( fuse_keysym == INPUT_KEY_NONE ) return 0;
 
   fuse_event.type = INPUT_EVENT_KEYPRESS;
-  fuse_event.types.key.key = fuse_keysym;
+  fuse_event.types.key.native_key = fuse_keysym;
+  fuse_event.types.key.spectrum_key = fuse_keysym;
 
   return input_event( &fuse_event );
 }
@@ -91,7 +92,8 @@
   if( fuse_keysym == INPUT_KEY_NONE ) return 0;
 
   fuse_event.type = INPUT_EVENT_KEYRELEASE;
-  fuse_event.types.key.key = fuse_keysym;
+  fuse_event.types.key.native_key = fuse_keysym;
+  fuse_event.types.key.spectrum_key = fuse_keysym;
 
   return input_event( &fuse_event );
 }
