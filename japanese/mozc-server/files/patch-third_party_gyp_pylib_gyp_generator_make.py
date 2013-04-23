--- third_party/gyp/pylib/gyp/generator/make.py.orig	2013-04-21 03:48:44.552270209 +0900
+++ third_party/gyp/pylib/gyp/generator/make.py	2013-04-21 04:16:32.828269137 +0900
@@ -1956,6 +1956,9 @@
     srcdir_prefix = '$(srcdir)/'
 
   flock_command= 'flock'
+  if os.uname()[0] == 'FreeBSD':
+    flock_command= 'lockf'
+
   header_params = {
       'default_target': default_target,
       'builddir': builddir_name,
