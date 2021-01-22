--- electron/script/lib/config.py.orig	2020-05-18 21:17:08 UTC
+++ electron/script/lib/config.py
@@ -21,6 +21,9 @@ BASE_URL = os.getenv('LIBCHROMIUMCONTENT_MIRROR') or \
 PLATFORM = {
   'cygwin': 'win32',
   'darwin': 'darwin',
+  'freebsd11': 'freebsd',
+  'freebsd12': 'freebsd',
+  'freebsd13': 'freebsd',
   'linux': 'linux',
   'linux2': 'linux',
   'win32': 'win32',
