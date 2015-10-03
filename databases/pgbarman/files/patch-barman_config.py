--- barman/config.py.orig	2015-09-25 15:06:25 UTC
+++ barman/config.py
@@ -429,8 +429,8 @@ class Config(object):
     """
     CONFIG_FILES = [
         '~/.barman.conf',
-        '/etc/barman.conf',
-        '/etc/barman/barman.conf',
+        '%%PREFIX%%/etc/barman.conf',
+        '%%PREFIX%%/etc/barman/barman.conf',
     ]
 
     _QUOTE_RE = re.compile(r"""^(["'])(.*)\1$""")
