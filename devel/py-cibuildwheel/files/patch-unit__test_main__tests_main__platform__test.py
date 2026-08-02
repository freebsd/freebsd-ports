--- unit_test/main_tests/main_platform_test.py.orig	2026-08-02 12:34:41.302162000 -0700
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
+        assert options.globals.architectures == {Architecture.AMD64}
     elif platform == "windows":
         assert options.globals.architectures == {Architecture.AMD64, Architecture.x86}
     else:
