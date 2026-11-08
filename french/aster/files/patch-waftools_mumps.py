--- waftools/mumps.py.orig	2026-09-11 16:05:37 UTC
+++ waftools/mumps.py
@@ -79,7 +79,7 @@ def check_mumps(self):
         raise Errors.ConfigurationError("MUMPS disabled")
     self.check_mumps_headers()
     try:
-        self.check_mumps_version(("5.7", "5.6", "5.5", "5.4"))
+        self.check_mumps_version(("5.9", "5.7", "5.6", "5.5", "5.4"))
     except Errors.ConfigurationError:
         self.check_mumps_version(("5.8",), beta=True)
     self.check_sizeof_mumps_integer()
