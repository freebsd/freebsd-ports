--- barman/config.py.orig	2014-08-01 13:50:46 UTC
+++ barman/config.py
@@ -341,8 +341,8 @@ class Config(object):
     """
     CONFIG_FILES = [
         '~/.barman.conf',
-        '/etc/barman.conf',
-        '/etc/barman/barman.conf',
+        '%%PREFIX%%/etc/barman.conf',
+        '%%PREFIX%%/etc/barman/barman.conf',
     ]
 
     _QUOTE_RE = re.compile(r"""^(["'])(.*)\1$""")
