https://github.com/exaile/exaile/issues/999

--- xl/player/gst/sink.py.orig	2025-12-08 18:00:20 UTC
+++ xl/player/gst/sink.py
@@ -83,7 +83,10 @@ def __filter_presets():
 def __filter_presets():
     for name, preset in list(SINK_PRESETS.items()):
         pipe = preset.get('pipe')
-        if pipe and not Gst.ElementFactory.make(pipe):
+        try:
+            if pipe and not Gst.ElementFactory.make(pipe):
+                del SINK_PRESETS[name]
+        except Exception:
             del SINK_PRESETS[name]
 
 
