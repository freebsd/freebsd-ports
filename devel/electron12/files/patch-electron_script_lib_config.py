--- electron/script/lib/config.py.orig	2021-10-11 17:12:26 UTC
+++ electron/script/lib/config.py
@@ -20,6 +20,9 @@ PLATFORM = {
   'cygwin': 'win32',
   'msys': 'win32',
   'darwin': 'darwin',
+  'freebsd12': 'freebsd',
+  'freebsd13': 'freebsd',
+  'freebsd14': 'freebsd',
   'linux': 'linux',
   'linux2': 'linux',
   'win32': 'win32',
