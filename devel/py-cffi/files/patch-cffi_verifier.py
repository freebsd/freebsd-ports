# Backport: PR #56: Actually check if the file exists rather than assume it doesn't
# https://bitbucket.org/cffi/cffi/pull-request/56/

--- cffi/verifier.py.orig	2015-02-11 08:57:05 UTC
+++ cffi/verifier.py
@@ -1,7 +1,16 @@
-import sys, os, binascii, imp, shutil
+import sys, os, binascii, imp, shutil, io
 from . import __version__
 from . import ffiplatform
 
+if sys.version_info >= (3,):
+    NativeIO = io.StringIO
+else:
+    class NativeIO(io.BytesIO):
+        def write(self, s):
+            if isinstance(s, unicode):
+                s = s.encode('ascii')
+            super(NativeIO, self).write(s)
+
 
 class Verifier(object):
 
@@ -118,19 +127,36 @@ class Verifier(object):
         self._vengine.collect_types()
         self._has_module = True
 
-    def _write_source(self, file=None):
-        must_close = (file is None)
-        if must_close:
-            _ensure_dir(self.sourcefilename)
-            file = open(self.sourcefilename, 'w')
+    def _write_source_to(self, file):
         self._vengine._f = file
         try:
             self._vengine.write_source_to_f()
         finally:
             del self._vengine._f
-            if must_close:
-                file.close()
-        if must_close:
+
+    def _write_source(self, file=None):
+        if file is not None:
+            self._write_source_to(file)
+        else:
+            # Write our source file to an in memory file.
+            f = NativeIO()
+            self._write_source_to(f)
+            source_data = f.getvalue()
+
+            # Determine if this matches the current file
+            if os.path.exists(self.sourcefilename):
+                with open(self.sourcefilename, "r") as fp:
+                    needs_written = not (fp.read() == source_data)
+            else:
+                needs_written = True
+
+            # Actually write the file out if it doesn't match
+            if needs_written:
+                _ensure_dir(self.sourcefilename)
+                with open(self.sourcefilename, "w") as fp:
+                    fp.write(source_data)
+
+            # Set this flag
             self._has_source = True
 
     def _compile_module(self):
