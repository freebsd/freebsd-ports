--- third_party/gyp/pylib/gyp/generator/make.py.orig	2012-04-02 08:17:52.711727455 +0900
+++ third_party/gyp/pylib/gyp/generator/make.py	2012-01-30 15:37:51.791889791 +0900
@@ -1998,6 +1998,9 @@
     srcdir_prefix = '$(srcdir)/'
 
   flock_command= 'flock'
+  if os.uname()[0] == 'FreeBSD':
+    flock_command= 'lockf'
+
   header_params = {
       'default_target': default_target,
       'builddir': builddir_name,
