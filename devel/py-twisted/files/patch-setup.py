--- setup.py.orig	Fri Sep 14 03:22:48 2001
+++ setup.py	Tue Sep 25 16:07:37 2001
@@ -80,8 +80,10 @@
     setup_args['platforms'] = "win32 posix"
 
 if os.name == 'posix':
-    import glob
-    setup_args['scripts'] = filter(os.path.isfile, glob.glob('bin/*'))
+    setup_args['scripts'] = ['bin/accepttests', 'bin/cpyrght', 'bin/faucet',
+                             'bin/gnusto', 'bin/im', 'bin/malyon',
+                             'bin/manhole', 'bin/mapeditor', 'bin/mktap',
+                             'bin/runtests', 'bin/twistd', 'bin/twistd-debug']
 
 #'"
 # for building C banana...
