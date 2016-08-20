--- src/etc/get-stage0.py.orig	2016-08-16 01:54:35 UTC
+++ src/etc/get-stage0.py
@@ -31,9 +31,8 @@ def main(triple):
     filename = 'rustc-{}-{}.tar.gz'.format(channel, triple)
     url = 'https://static.rust-lang.org/dist/{}/{}'.format(date, filename)
     dst = dl_dir + '/' + filename
-    if os.path.exists(dst):
-        os.unlink(dst)
-    bootstrap.get(url, dst)
+    if not os.path.exists(dst):
+        bootstrap.get(url, dst)
 
     stage0_dst = triple + '/stage0'
     if os.path.exists(stage0_dst):
