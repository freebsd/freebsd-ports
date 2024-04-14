--- electron/script/lib/config.py.orig	2024-02-21 16:26:48 UTC
+++ electron/script/lib/config.py
@@ -7,6 +7,9 @@ PLATFORM = {
   'cygwin': 'win32',
   'msys': 'win32',
   'darwin': 'darwin',
+  'freebsd12': 'freebsd',
+  'freebsd13': 'freebsd',
+  'freebsd14': 'freebsd',
   'linux': 'linux',
   'linux2': 'linux',
   'win32': 'win32',
