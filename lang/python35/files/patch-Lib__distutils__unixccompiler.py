# Description: Some python extensions can't be compiled with clang 3.4
# Issue ID: http://bugs.python.org/issue20767
# Submitted by: antoine

--- ./Lib/distutils/unixccompiler.py.orig	2014-03-09 15:25:15.921204441 +1100
+++ ./Lib/distutils/unixccompiler.py	2014-03-09 15:25:50.643809649 +1100
@@ -225,6 +225,8 @@
         if sys.platform[:6] == "darwin":
             # MacOSX's linker doesn't understand the -R flag at all
             return "-L" + dir
+        elif sys.platform[:7] == "freebsd":
+            return "-Wl,-rpath=" + dir
         elif sys.platform[:5] == "hp-ux":
             if self._is_gcc(compiler):
                 return ["-Wl,+s", "-L" + dir]
