Fix arguments that are passed to mpv.  Otherwise mpv terminates with an error
as it expects option values passed after a '=' since 0.31.0.

Backported and adapted for the 2.1.16 release.

Obtained from: https://github.com/ankitects/anki/commit/ccd715013609133c55e83924734efa78abc03326

--- anki/mpv.py.orig	2020-02-18 09:38:27 UTC
+++ anki/mpv.py
@@ -104,9 +104,9 @@ class MPVBase:
         """
         self.argv = [self.executable]
         self.argv += self.default_argv
-        self.argv += ["--input-ipc-server", self._sock_filename]
+        self.argv += ["--input-ipc-server="+self._sock_filename]
         if self.window_id is not None:
-            self.argv += ["--wid", str(self.window_id)]
+            self.argv += ["--wid="+str(self.window_id)]
 
     def _start_process(self):
         """Start the mpv process.
