--- setup.py.orig	Wed Sep 25 20:00:05 2002
+++ setup.py	Mon Sep 30 11:13:52 2002
@@ -311,7 +311,7 @@
 if os.name == 'posix':
     setup_args['scripts'] = [
         'bin/manhole', 'bin/mktap', 'bin/twistd',
-        'bin/im', 'bin/t-im', 'bin/tap2deb',
+        'bin/im', 'bin/t-im',
         'bin/coil', 'bin/tapconvert',
     ]
 else:
