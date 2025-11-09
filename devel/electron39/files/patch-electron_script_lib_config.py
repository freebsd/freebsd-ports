--- electron/script/lib/config.py.orig	2024-05-29 09:41:07 UTC
+++ electron/script/lib/config.py
@@ -7,6 +7,9 @@ PLATFORM = {
   'cygwin': 'win32',
   'msys': 'win32',
   'darwin': 'darwin',
+  'freebsd13': 'freebsd',
+  'freebsd14': 'freebsd',
+  'freebsd15': 'freebsd',
   'linux': 'linux',
   'linux2': 'linux',
   'win32': 'win32',
