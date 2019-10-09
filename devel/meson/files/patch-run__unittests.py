https://github.com/mesonbuild/meson/pull/4324
https://github.com/mesonbuild/meson/pull/4325
https://github.com/mesonbuild/meson/pull/6007

--- run_unittests.py.orig	2019-10-06 17:01:35 UTC
+++ run_unittests.py
@@ -57,6 +57,7 @@ from mesonbuild.mesonlib import (
 from mesonbuild.environment import detect_ninja
 from mesonbuild.mesonlib import MesonException, EnvironmentException
 from mesonbuild.dependencies import PkgConfigDependency, ExternalProgram
+import mesonbuild.dependencies.base
 from mesonbuild.build import Target
 import mesonbuild.modules.pkgconfig
 
@@ -1164,7 +1165,26 @@ class InternalTests(unittest.TestCase):
             deps = d.get_all_dependencies(target)
             self.assertEqual(deps, expdeps)
 
+    def test_sort_libpaths(self):
+        sort_libpaths = mesonbuild.dependencies.base.sort_libpaths
+        self.assertEqual(sort_libpaths(
+            ['/home/mesonuser/.local/lib', '/usr/local/lib', '/usr/lib'],
+            ['/home/mesonuser/.local/lib/pkgconfig', '/usr/local/lib/pkgconfig']),
+            ['/home/mesonuser/.local/lib', '/usr/local/lib', '/usr/lib'])
+        self.assertEqual(sort_libpaths(
+            ['/usr/local/lib', '/home/mesonuser/.local/lib', '/usr/lib'],
+            ['/home/mesonuser/.local/lib/pkgconfig', '/usr/local/lib/pkgconfig']),
+            ['/home/mesonuser/.local/lib', '/usr/local/lib', '/usr/lib'])
+        self.assertEqual(sort_libpaths(
+            ['/usr/lib', '/usr/local/lib', '/home/mesonuser/.local/lib'],
+            ['/home/mesonuser/.local/lib/pkgconfig', '/usr/local/lib/pkgconfig']),
+            ['/home/mesonuser/.local/lib', '/usr/local/lib', '/usr/lib'])
+        self.assertEqual(sort_libpaths(
+            ['/usr/lib', '/usr/local/lib', '/home/mesonuser/.local/lib'],
+            ['/home/mesonuser/.local/lib/pkgconfig', '/usr/local/libdata/pkgconfig']),
+            ['/home/mesonuser/.local/lib', '/usr/local/lib', '/usr/lib'])
 
+
 @unittest.skipIf(is_tarball(), 'Skipping because this is a tarball release')
 class DataTests(unittest.TestCase):
 
@@ -5643,6 +5664,7 @@ class LinuxlikeTests(BasePlatformTests):
                 # Assert that
                 self.assertEqual(len(line.split(lib)), 2, msg=(lib, line))
 
+    @skipIfNoPkgconfig
     def test_noncross_options(self):
         # C_std defined in project options must be in effect also when native compiling.
         testdir = os.path.join(self.unit_test_dir, '51 noncross options')
@@ -5665,6 +5687,7 @@ c = ['{0}']
         # TODO should someday be explicit about build platform only here
         self.init(testdir, override_envvars=env)
 
+    @skipIfNoPkgconfig
     def test_static_link(self):
         if is_cygwin():
             raise unittest.SkipTest("Cygwin doesn't support LD_LIBRARY_PATH.")
@@ -5680,7 +5703,7 @@ c = ['{0}']
         # Test that installed libraries works
         self.new_builddir()
         self.prefix = oldprefix
-        meson_args = ['-Dc_link_args=-L{}'.format(libdir),
+        meson_args = ['-Dc_link_args=-L{} -Wl,-rpath,{}'.format(libdir, libdir),
                       '--fatal-meson-warnings']
         testdir = os.path.join(self.unit_test_dir, '69 static link')
         env = {'PKG_CONFIG_LIBDIR': os.path.join(libdir, 'pkgconfig')}
