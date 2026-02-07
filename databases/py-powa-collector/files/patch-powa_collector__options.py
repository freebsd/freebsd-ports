--- powa_collector/options.py.orig	2024-11-03 01:42:37 UTC
+++ powa_collector/options.py
@@ -18,7 +18,7 @@ CONF_LOCATIONS = [
 """
 
 CONF_LOCATIONS = [
-    '/etc/powa-collector.conf',
+    '/usr/local/etc/powa-collector.conf',
     os.path.expanduser('~/.config/powa-collector.conf'),
     os.path.expanduser('~/.powa-collector.conf'),
     './powa-collector.conf'
