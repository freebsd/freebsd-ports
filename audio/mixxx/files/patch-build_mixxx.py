--- build/mixxx.py.orig	2015-12-29 16:10:41 UTC
+++ build/mixxx.py
@@ -380,9 +380,9 @@ class MixxxBuild(object):
             self.env['LINKFLAGS'] += SCons.Util.CLVar(os.environ['LDFLAGS'])
 
         # Allow installation directories to be specified.
-        prefix = Script.ARGUMENTS.get('prefix', '/usr/local')
+        prefix = Script.ARGUMENTS.get('prefix', '%%PREFIX%%')
         if os.environ.has_key('LIBDIR'):
-            self.env['LIBDIR'] = os.path.relpath(os.environ['LIBDIR'], prefix)
+            self.env['LIBDIR'] = 'lib' # os.path.relpath(os.environ['LIBDIR'], prefix)
         if os.environ.has_key('BINDIR'):
             self.env['BINDIR'] = os.path.relpath(os.environ['BINDIR'], prefix)
         if os.environ.has_key('SHAREDIR'):
