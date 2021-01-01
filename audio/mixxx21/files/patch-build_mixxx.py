--- build/mixxx.py	2018-04-15 13:30:27.000000000 -0500
+++ build/mixxx.py	2018-04-21 22:31:31.694426000 -0500
@@ -394,9 +394,9 @@
             self.env['LINKFLAGS'] += SCons.Util.CLVar(os.environ['LDFLAGS'])
 
         # Allow installation directories to be specified.
-        prefix = Script.ARGUMENTS.get('prefix', '/usr/local')
+        prefix = Script.ARGUMENTS.get('prefix', '%%PREFIX%%')
         if 'LIBDIR' in os.environ:
-            self.env['LIBDIR'] = os.path.relpath(os.environ['LIBDIR'], prefix)
+            self.env['LIBDIR'] = 'lib' # os.path.relpath(os.environ['LIBDIR'], prefix)
         if 'BINDIR' in os.environ:
             self.env['BINDIR'] = os.path.relpath(os.environ['BINDIR'], prefix)
         if 'SHAREDIR' in os.environ:
@@ -429,10 +429,10 @@
     def install_options(self):
         cachefile = os.path.join(self.get_cache_dir(), 'custom.py')
         vars = Script.Variables(cachefile)
-        vars.Add('prefix', 'Set to your install prefix', '/usr/local')
+        vars.Add('prefix', 'Set to your install prefix', '%%PREFIX%%')
         vars.Add('virtualize',
                  'Dynamically swap out the build directory when switching Git branches.', 1)
-        vars.Add('qtdir', 'Set to your QT4 directory', '/usr/share/qt4')
+        vars.Add('qtdir', 'Set to your QT4 directory', '%%LOCALBASE%%/share/qt4')
         vars.Add('qt_sqlite_plugin', 'Set to 1 to package the Qt SQLite plugin.'
                  '\n           Set to 0 if SQLite support is compiled into QtSQL.', 0)
         vars.Add('target',
