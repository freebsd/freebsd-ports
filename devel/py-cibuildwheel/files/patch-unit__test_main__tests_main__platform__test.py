--- unit_test/main_tests/main_platform_test.py.orig	2025-03-31 08:24:58 UTC
+++ unit_test/main_tests/main_platform_test.py
@@ -25,6 +25,8 @@ def test_platform_unset_or_auto(monkeypatch, intercept
     # check that the platform was auto detected to build for the current system
     if sys.platform.startswith("linux"):
         assert options.platform == "linux"
+    elif sys.platform.startswith("freebsd"):
+        assert options.platform == "freebsd"
     elif sys.platform == "darwin":
         assert options.platform == "macos"
     elif sys.platform == "win32":
@@ -82,6 +84,8 @@ def test_archs_default(platform, intercepted_build_arg
 
     if platform == "linux":
         assert options.globals.architectures == {Architecture.x86_64, Architecture.i686}
+    elif platform == "freebsd":
+        assert options.globals.architectures == {Architecture.AMD64, Architecture.x86}
     elif platform == "windows":
         assert options.globals.architectures == {Architecture.AMD64, Architecture.x86}
     else:
