--- src/tk/soundoptionsdialog.py.orig	2004-12-04 15:33:34.218987696 +0200
+++ src/tk/soundoptionsdialog.py	2004-12-04 15:29:08.306412552 +0200
@@ -47,6 +47,11 @@
 from tkconst import EVENT_HANDLED, EVENT_PROPAGATE
 from tkwidget import _ToplevelDialog, MfxDialog
 
+def bool2int(b):
+    if b:
+        return 1
+    else:
+        return 0
 
 # /***********************************************************************
 # //
@@ -114,7 +119,7 @@
 
     def mDone(self, button):
         if button == 0 or button == 1:
-            self.app.opt.sound = self.sound.get()
+            self.app.opt.sound = bool2int(self.sound.get())
             self.app.opt.sound_mode = self.sound_mode.get()
             self.app.opt.sound_sample_volume = self.sample_volume.get()
             self.app.opt.sound_music_volume = self.music_volume.get()
