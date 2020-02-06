--- electron/script/lib/config.py.orig	2019-12-20 06:16:27 UTC
+++ electron/script/lib/config.py
@@ -21,6 +21,9 @@ PLATFORM = {
   'cygwin': 'win32',
   'darwin': 'darwin',
   'linux2': 'linux',
+  'freebsd11': 'freebsd',
+  'freebsd12': 'freebsd',
+  'freebsd13': 'freebsd',
   'win32': 'win32',
 }[sys.platform]
 
