--- electron/script/lib/config.py.orig	2026-03-05 10:29:21 UTC
+++ electron/script/lib/config.py
@@ -7,6 +7,10 @@ PLATFORM = {
   'cygwin': 'win32',
   'msys': 'win32',
   'darwin': 'darwin',
+  'freebsd13': 'freebsd',
+  'freebsd14': 'freebsd',
+  'freebsd15': 'freebsd',
+  'freebsd16': 'freebsd',
   'linux': 'linux',
   'linux2': 'linux',
   'win32': 'win32',
