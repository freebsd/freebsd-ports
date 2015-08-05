--- pypy/tool/release/package.py.orig	2015-05-31 07:19:51 UTC
+++ pypy/tool/release/package.py
@@ -135,7 +135,7 @@ def create_package(basedir, options, _fa
                                 'not find it' % (str(libpypy_c),))
         binaries.append((libpypy_c, libpypy_name))
     #
-    builddir = options.builddir
+    builddir = py.path.local(options.builddir)
     pypydir = builddir.ensure(name, dir=True)
     includedir = basedir.join('include')
     # Recursively copy all headers, shutil has only ignore
