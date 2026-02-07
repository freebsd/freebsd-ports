--- normcap/screengrab/handlers/dbus_portal.py.orig	2024-05-19 21:44:57 UTC
+++ normcap/screengrab/handlers/dbus_portal.py
@@ -216,7 +216,7 @@ def is_compatible() -> bool:
 
 def is_compatible() -> bool:
     # TODO: Specify closer!
-    return sys.platform == "linux"
+    return sys.platform == "linux" or sys.platform == "freebsd"
 
 
 def is_installed() -> bool:
