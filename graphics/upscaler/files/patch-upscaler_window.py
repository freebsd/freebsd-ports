Avoid spurious error "Algorithm failed" as poll() returns None when
the subprocess hasn't finished yet.

--- upscaler/window.py.orig	2022-12-10 21:01:05 UTC
+++ upscaler/window.py
@@ -203,7 +203,7 @@ class UpscalerWindow(Adw.ApplicationWindow):
                             bad = True
                             continue
             """ Process algorithm output. """
-            result = self.process.poll()
+            result = self.process.wait(1)
             if result != 0:
                 raise AlgorithmFailed(result, output)
             if bad:
