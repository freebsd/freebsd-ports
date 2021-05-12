--- electron/script/lib/config.py.orig	2021-04-20 23:32:33 UTC
+++ electron/script/lib/config.py
@@ -19,6 +19,9 @@ BASE_URL = os.getenv('LIBCHROMIUMCONTENT_MIRROR') or \
 PLATFORM = {
   'cygwin': 'win32',
   'darwin': 'darwin',
+  'freebsd11': 'freebsd',
+  'freebsd12': 'freebsd',
+  'freebsd13': 'freebsd',
   'linux': 'linux',
   'linux2': 'linux',
   'win32': 'win32',
