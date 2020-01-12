https://github.com/mesonbuild/meson/pull/4324

--- run_unittests.py.orig	2019-10-06 17:01:35 UTC
+++ run_unittests.py
@@ -5680,7 +5703,7 @@ c = ['{0}']
         # Test that installed libraries works
         self.new_builddir()
         self.prefix = oldprefix
-        meson_args = ['-Dc_link_args=-L{}'.format(libdir),
+        meson_args = ['-Dc_link_args=-L{} -Wl,-rpath,{}'.format(libdir, libdir),
                       '--fatal-meson-warnings']
         testdir = os.path.join(self.unit_test_dir, '69 static link')
         env = {'PKG_CONFIG_LIBDIR': os.path.join(libdir, 'pkgconfig')}
