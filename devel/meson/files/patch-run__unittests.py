https://github.com/mesonbuild/meson/pull/4324

--- run_unittests.py.orig	2021-05-02 09:37:39 UTC
+++ run_unittests.py
@@ -7840,7 +7840,7 @@ class LinuxlikeTests(BasePlatformTests):
         # Test that installed libraries works
         self.new_builddir()
         self.prefix = oldprefix
-        meson_args = [f'-Dc_link_args=-L{libdir}',
+        meson_args = [f'-Dc_link_args=-L{libdir} -Wl,-rpath,{libdir}',
                       '--fatal-meson-warnings']
         testdir = os.path.join(self.unit_test_dir, '67 static link')
         env = {'PKG_CONFIG_LIBDIR': os.path.join(libdir, 'pkgconfig')}
