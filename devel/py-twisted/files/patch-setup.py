--- setup.py.orig	Thu Apr 18 21:49:03 2002
+++ setup.py	Wed Apr 24 11:15:18 2002
@@ -216,7 +216,7 @@
 if os.name == 'posix':
     setup_args['scripts'] = [
         'bin/manhole', 'bin/mktap', 'bin/twistd',
-        'bin/im', 'bin/t-im', 'bin/tap2deb',
+        'bin/im', 'bin/t-im',
         'bin/coil',
     ]
 else:
