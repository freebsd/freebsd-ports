diff --git src/lib/accerciser/accerciser.py src/lib/accerciser/accerciser.py
index fa6e5c752c2b921ab5cb324b747c0080e65f5f82..065a7fec78c62cb79acdda6fee7adc1097c586cf 100644
--- src/lib/accerciser/accerciser.py
+++ src/lib/accerciser/accerciser.py
@@ -103,7 +103,8 @@ class Main(Tools):
     '''
     GLib.timeout_add(200, self._pumpEvents)
     try:
-      pyatspi.Registry.start(async=True, gil=False)
+      # async is a reserved keyword in Python 3.7+, so we pass the args as dict
+      pyatspi.Registry.start(**{'async': True, 'gil': False})
     except KeyboardInterrupt:
       self._shutDown()
 
