--- config/v8/__init__.py.orig	2023-03-09 16:36:47 UTC
+++ config/v8/__init__.py
@@ -8,13 +8,17 @@ def configure(conf):
     else: lib_suffix.append('/build/Debug/lib')
 
     if not 'V8_INCLUDE' in os.environ and not 'V8_HOME' in os.environ:
-        os.environ['V8_INCLUDE'] = '/usr/include/v8'
+        os.environ['V8_INCLUDE'] = '/usr/local/include'
 
     conf.CBCheckHome('v8', lib_suffix = lib_suffix)
 
     if conf.env['PLATFORM'] == 'win32' or int(conf.env.get('cross_mingw', 0)):
         conf.CBRequireLib('winmm')
         conf.CBCheckLib('dbghelp')
+
+    # V8 >= 15.4 refuses to compile unless the embedder defines this
+    conf.env.AppendUnique(CPPDEFINES = ['V8_CPPGC_MICROTASK_QUEUE=1'])
+    conf.env.CBConfigDef('V8_CPPGC_MICROTASK_QUEUE=1')
 
     conf.CBRequireCXXHeader('v8.h')
     conf.CBRequireCXXHeader('libplatform/libplatform.h')
