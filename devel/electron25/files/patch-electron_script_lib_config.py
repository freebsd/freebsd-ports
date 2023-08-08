--- electron/script/lib/config.py.orig	2021-11-08 18:41:28 UTC
+++ electron/script/lib/config.py
@@ -8,6 +8,9 @@ PLATFORM = {
   'cygwin': 'win32',
   'msys': 'win32',
   'darwin': 'darwin',
+  'freebsd12': 'freebsd',
+  'freebsd13': 'freebsd',
+  'freebsd14': 'freebsd',
   'linux': 'linux',
   'linux2': 'linux',
   'win32': 'win32',
