--- tests/tests_e3/env/main_test.py.orig	2025-05-09 08:40:30 UTC
+++ tests/tests_e3/env/main_test.py
@@ -15,6 +15,9 @@ def test_autodetect():
         .replace("win32", "windows")
         .replace("aix7", "aix")
         .replace("sunos5", "solaris")
+        .replace("freebsd13", "freebsd")
+        .replace("freebsd14", "freebsd")
+        .replace("freebsd15", "freebsd")
     )
     assert sys_platform in str(e3.platform.Platform.get())
 
