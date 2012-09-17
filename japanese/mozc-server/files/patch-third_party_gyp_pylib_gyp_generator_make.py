--- third_party/gyp/pylib/gyp/generator/make.py.orig	2012-09-07 10:21:29.146021648 +0900
+++ third_party/gyp/pylib/gyp/generator/make.py	2012-09-17 17:15:20.613807429 +0900
@@ -1963,6 +1963,9 @@
     srcdir_prefix = '$(srcdir)/'
 
   flock_command= 'flock'
+  if os.uname()[0] == 'FreeBSD':
+    flock_command= 'lockf'
+
   header_params = {
       'default_target': default_target,
       'builddir': builddir_name,
