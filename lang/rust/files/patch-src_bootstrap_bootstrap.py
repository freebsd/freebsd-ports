--- src/bootstrap/bootstrap.py.orig	2019-01-16 09:30:27 UTC
+++ src/bootstrap/bootstrap.py
@@ -240,6 +240,10 @@ def default_build_triple():
         err = "unknown OS type: {}".format(ostype)
         sys.exit(err)
 
+    if cputype == 'powerpc' and ostype == 'unknown-freebsd':
+        cputype = subprocess.check_output(
+              ['uname', '-p']).strip().decode(default_encoding)
+
     cputype_mapper = {
         'BePC': 'i686',
         'aarch64': 'aarch64',
@@ -269,6 +273,10 @@ def default_build_triple():
         cputype = 'arm'
         if ostype == 'linux-android':
             ostype = 'linux-androideabi'
+        elif ostype == 'unknown-freebsd':
+            cputype = subprocess.check_output(
+                ['uname', '-p']).strip().decode(default_encoding)
+            ostype = 'unknown-freebsd'
     elif cputype == 'armv6l':
         cputype = 'arm'
         if ostype == 'linux-android':
