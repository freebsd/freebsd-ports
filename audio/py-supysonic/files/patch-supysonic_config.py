--- supysonic/config.py.orig	2023-04-08 00:33:44 UTC
+++ supysonic/config.py
@@ -61,7 +61,7 @@ class DefaultConfig:
 
 class IniConfig(DefaultConfig):
     common_paths = [
-        "/etc/supysonic",
+        os.path.join(sys.prefix, "etc/supysonic/supysonic.conf"),
         os.path.expanduser("~/.supysonic"),
         os.path.expanduser("~/.config/supysonic/supysonic.conf"),
         "supysonic.conf",
