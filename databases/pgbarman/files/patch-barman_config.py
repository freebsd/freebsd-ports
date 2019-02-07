--- barman/config.py.orig	2019-01-31 16:56:08 UTC
+++ barman/config.py
@@ -566,8 +566,8 @@ class Config(object):
     """
     CONFIG_FILES = [
         '~/.barman.conf',
-        '/etc/barman.conf',
-        '/etc/barman/barman.conf',
+        '%%PREFIX%%/etc/barman.conf',
+        '%%PREFIX%%/etc/barman/barman.conf',
     ]
 
     _QUOTE_RE = re.compile(r"""^(["'])(.*)\1$""")
