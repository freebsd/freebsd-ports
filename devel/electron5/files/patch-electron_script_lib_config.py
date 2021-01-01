--- electron/script/lib/config.py.orig	2019-12-19 06:24:18 UTC
+++ electron/script/lib/config.py
@@ -21,6 +21,8 @@ PLATFORM = {
   'cygwin': 'win32',
   'darwin': 'darwin',
   'linux2': 'linux',
+  'freebsd11': 'freebsd',
+  'freebsd12': 'freebsd',
   'win32': 'win32',
 }[sys.platform]
 
