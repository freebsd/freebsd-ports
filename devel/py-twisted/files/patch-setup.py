--- setup.py.orig	Mon Jan 28 11:41:12 2002
+++ setup.py	Wed Feb 13 15:20:01 2002
@@ -82,8 +82,11 @@
     setup_args['platforms'] = "win32 posix"
 
 if os.name == 'posix':
-    import glob
-    setup_args['scripts'] = filter(os.path.isfile, glob.glob('bin/*'))
+    setup_args['scripts'] = ['bin/accepttests', 'bin/cpyrght', 'bin/faucet',
+                             'bin/gnusto', 'bin/im', 'bin/malyon',
+                             'bin/manhole', 'bin/mapeditor', 'bin/mktap',
+                             'bin/runtests', 'bin/t-im', 'bin/twistd',
+                             'bin/twistd-debug']
 
 #'"
 # for building C banana...
