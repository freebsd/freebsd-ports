--- third_party/gyp/pylib/gyp/generator/make.py.orig	2012-05-29 15:36:59.732960259 +0900
+++ third_party/gyp/pylib/gyp/generator/make.py	2012-05-01 12:46:18.211693101 +0900
@@ -1963,6 +1963,9 @@
     srcdir_prefix = '$(srcdir)/'
 
   flock_command= 'flock'
+  if os.uname()[0] == 'FreeBSD':
+    flock_command= 'lockf'
+
   header_params = {
       'default_target': default_target,
       'builddir': builddir_name,
