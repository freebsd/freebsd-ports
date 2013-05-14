--- third_party/gyp/pylib/gyp/generator/make.py.orig	2013-02-26 11:59:54.000000000 +0900
+++ third_party/gyp/pylib/gyp/generator/make.py	2013-05-03 21:08:15.000000000 +0900
@@ -259,7 +259,7 @@
 #   export LINK=g++
 #
 # This will allow make to invoke N linker processes as specified in -jN.
-LINK ?= %(flock)s $(builddir)/linker.lock $(CXX.target)
+LINK ?= $(CXX.target)
 
 CC.target ?= %(CC.target)s
 CFLAGS.target ?= $(CFLAGS)
@@ -1956,6 +1956,9 @@
     srcdir_prefix = '$(srcdir)/'
 
   flock_command= 'flock'
+  if os.uname()[0] == 'FreeBSD':
+    flock_command= 'lockf'
+
   header_params = {
       'default_target': default_target,
       'builddir': builddir_name,
@@ -2003,7 +2006,8 @@
   build_file, _, _ = gyp.common.ParseQualifiedTarget(target_list[0])
   make_global_settings_array = data[build_file].get('make_global_settings', [])
   wrappers = {}
-  wrappers['LINK'] = '%s $(builddir)/linker.lock' % flock_command
+  # Disable flock for linking.
+  # wrappers['LINK'] = '%s $(builddir)/linker.lock' % flock_command
   for key, value in make_global_settings_array:
     if key.endswith('_wrapper'):
       wrappers[key[:-len('_wrapper')]] = '$(abspath %s)' % value
