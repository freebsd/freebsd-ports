-- Add FreeBSD to the list of recognized operating systems in test_probe.py
-- FreeBSD support was added to probe.py but the test still expected only
-- the original OS list. This patch adds FreeBSD to the assertion.

--- src/setuptools_dso/test/test_probe.py.orig	2026-02-11 01:15:48 UTC
+++ src/setuptools_dso/test/test_probe.py
@@ -79,7 +79,7 @@ is a test
 
         self.assertIn(info.compiler, ('clang', 'gcc', 'msvc'))
         self.assertGreater(info.compiler_version, (0,))
-        self.assertIn(info.target_os, ("cygwin", "linux", "osx", "windows"))
+        self.assertIn(info.target_os, ("cygwin", "freebsd", "linux", "osx", "windows"))
         self.assertIn(info.target_arch, ("aarch64", "arm32", "amd64", "i386"))
         self.assertIn(info.address_width, (32, 64))
         self.assertIn(info.endian, ("little", "big"))
