--- setup.py.orig	2012-04-20 19:35:36.898907237 +0600
+++ setup.py	2012-04-20 19:35:49.460978953 +0600
@@ -56,9 +56,6 @@
     man_dir = 'share/man'
 
 data_files = [
-    # man pages
-    (os.path.join(man_dir, 'man1'), ['doc/bpython.1']),
-    (os.path.join(man_dir, 'man5'), ['doc/bpython-config.5']),
     # desktop shortcut
     (os.path.join('share', 'applications'), ['data/bpython.desktop'])
 ]
