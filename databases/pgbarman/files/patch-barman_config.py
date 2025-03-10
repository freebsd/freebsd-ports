--- barman/config.py.orig	2024-11-23 11:42:48 UTC
+++ barman/config.py
@@ -1194,15 +1194,15 @@ class Config(object):
 class Config(object):
     """This class represents the barman configuration.
 
-    Default configuration files are /etc/barman.conf,
-    /etc/barman/barman.conf
+    Default configuration files are %%PREFIX%%/etc/barman.conf,
+    %%PREFIX%%/etc/barman/barman.conf
     and ~/.barman.conf for a per-user configuration
     """
 
     CONFIG_FILES = [
         "~/.barman.conf",
-        "/etc/barman.conf",
-        "/etc/barman/barman.conf",
+        "%%PREFIX%%/etc/barman.conf",
+        "%%PREFIX%%/etc/barman/barman.conf",
     ]
 
     _QUOTE_RE = re.compile(r"""^(["'])(.*)\1$""")
