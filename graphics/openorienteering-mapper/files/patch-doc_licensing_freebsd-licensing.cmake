--- doc/licensing/freebsd-licensing.cmake.orig	2018-08-23 17:44:26 UTC
+++ doc/licensing/freebsd-licensing.cmake
@@ -0,0 +1,6 @@
+include("linux-distribution.cmake")
+
+set(system_copyright_dir "/usr/local/share/licenses")
+set(copyright_pattern
+  "${system_copyright_dir}/@package@/LICENSE"
+)
