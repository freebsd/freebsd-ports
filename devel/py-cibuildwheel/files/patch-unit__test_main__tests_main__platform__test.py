-- Teach the unit tests that cibuildwheel detects FreeBSD as a platform and
-- that the native amd64 architecture maps to x86_64 (not the Windows-only
-- AMD64 enum member).

--- unit_test/main_tests/main_platform_test.py.orig	2026-09-14 15:11:41 UTC
+++ unit_test/main_tests/main_platform_test.py
@@ -35,6 +35,8 @@ def test_platform_unset_or_auto(
     # check that the platform was auto detected to build for the current system
     if sys.platform.startswith("linux"):
         assert options.platform == "linux"
+    elif sys.platform.startswith("freebsd"):
+        assert options.platform == "freebsd"
     elif sys.platform == "darwin":
         assert options.platform == "macos"
     elif sys.platform == "win32":
@@ -98,6 +100,8 @@ def test_archs_default(platform: str, intercepted_build_args: ArgsInterceptor)

     if platform == "linux":
         assert options.globals.architectures == {Architecture.x86_64}
+    elif platform == "freebsd":
+        assert options.globals.architectures == {Architecture.x86_64}
     elif platform == "windows":
         assert options.globals.architectures == {Architecture.AMD64, Architecture.x86}
     else:
