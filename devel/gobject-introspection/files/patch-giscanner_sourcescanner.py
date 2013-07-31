--- giscanner/sourcescanner.py.orig	2013-03-06 23:53:19.000000000 +0100
+++ giscanner/sourcescanner.py	2013-06-28 22:01:04.000000000 +0200
@@ -281,8 +281,11 @@
         # some help from gcc from MinGW/Cygwin or so.
         # Note that the generated dumper program is
         # still built and linked by Visual C++.
-        if 'cl' in cpp_exec:
-            cpp_args = 'gcc'.split()
+        if 'clang' not in cpp_exec:
+            if 'cl' in cpp_exec:
+                cpp_args = 'gcc'.split()
+            else:
+	        cpp_args = cpp_exec
         else:
             cpp_args = cpp_exec
         cpp_args += ['-E', '-C', '-I.', '-']
