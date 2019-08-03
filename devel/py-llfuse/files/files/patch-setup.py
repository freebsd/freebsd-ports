--- setup.py.orig	2017-01-22 22:24:10 UTC
+++ setup.py
@@ -80,24 +80,24 @@ def main():
     # We may have unused functions if we compile for older FUSE versions
     compile_args.append('-Wno-unused-function')
 
-    # Value-changing conversions should always be explicit.
-    compile_args.append('-Werror=conversion')
-
-    # Note that (i > -1) is false if i is unsigned (-1 will be converted to
-    # a large positive value). We certainly don't want to do this by
-    # accident.
-    compile_args.append('-Werror=sign-compare')
-
     # Enable all fatal warnings only when compiling from Mercurial tip.
     # (otherwise we break forward compatibility because compilation with newer
     # compiler may fail if additional warnings are added)
-    if DEVELOPER_MODE:
+    if 0:
         compile_args.append('-Werror')
         compile_args.append('-Wfatal-errors')
 
         # Unreachable code is expected because we need to support multiple
         # platforms and architectures.
         compile_args.append('-Wno-error=unreachable-code')
+
+        # Value-changing conversions should always be explicit.
+        compile_args.append('-Werror=conversion')
+
+        # Note that (i > -1) is false if i is unsigned (-1 will be converted to
+        # a large positive value). We certainly don't want to do this by
+        # accident.
+        compile_args.append('-Werror=sign-compare')
 
     # http://bugs.python.org/issue7576
     if sys.version_info[0] == 3 and sys.version_info[1] < 2:
