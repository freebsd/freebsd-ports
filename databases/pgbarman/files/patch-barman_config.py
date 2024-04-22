--- barman/config.py.orig	2023-10-03 12:56:33 UTC
+++ barman/config.py
@@ -802,8 +802,8 @@ class Config(object):
 
     CONFIG_FILES = [
         "~/.barman.conf",
-        "/etc/barman.conf",
-        "/etc/barman/barman.conf",
+        "%%PREFIX%%/etc/barman.conf",
+        "%%PREFIX%%/etc/barman/barman.conf",
     ]
 
     _QUOTE_RE = re.compile(r"""^(["'])(.*)\1$""")
