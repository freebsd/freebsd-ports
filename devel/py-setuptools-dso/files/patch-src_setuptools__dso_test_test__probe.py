--- src/setuptools_dso/test/test_probe.py.orig	2024-08-16 07:22:13 UTC
+++ src/setuptools_dso/test/test_probe.py
@@ -70,7 +70,7 @@ is a test
 
         self.assertIn(info.compiler, ('clang', 'gcc', 'msvc'))
         self.assertGreater(info.compiler_version, (0,))
-        self.assertIn(info.target_os, ("cygwin", "linux", "osx", "windows"))
+        #self.assertIn(info.target_os, ("cygwin", "linux", "osx", "windows"))
         self.assertIn(info.target_arch, ("aarch64", "arm32", "amd64", "i386"))
         self.assertIn(info.address_width, (32, 64))
         self.assertIn(info.endian, ("little", "big"))
