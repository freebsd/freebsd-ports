--- barman/config.py.orig	2021-12-01 11:09:36 UTC
+++ barman/config.py
@@ -661,8 +661,8 @@ class Config(object):
 
     CONFIG_FILES = [
         "~/.barman.conf",
-        "/etc/barman.conf",
-        "/etc/barman/barman.conf",
+        "%%PREFIX%%/etc/barman.conf",
+        "%%PREFIX%%/etc/barman/barman.conf",
     ]
 
     _QUOTE_RE = re.compile(r"""^(["'])(.*)\1$""")
