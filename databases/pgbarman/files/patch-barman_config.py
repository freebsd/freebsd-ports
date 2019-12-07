--- barman/config.py.orig	2019-12-02 10:19:28 UTC
+++ barman/config.py
@@ -592,8 +592,8 @@ class Config(object):
     """
     CONFIG_FILES = [
         '~/.barman.conf',
-        '/etc/barman.conf',
-        '/etc/barman/barman.conf',
+        '%%PREFIX%%/etc/barman.conf',
+        '%%PREFIX%%/etc/barman/barman.conf',
     ]
 
     _QUOTE_RE = re.compile(r"""^(["'])(.*)\1$""")
