Description: get_linux_distro() opened /etc/lsb-release with the 'rU' mode,
  removed in Python 3.11, and called platform.dist(), removed in Python
  3.8; open it in text mode and only call platform.dist() where it exists.
Issue ID: https://github.com/tpltnt/pyutil/pull/15
Changeset: none (pyutil 3.4.1 still has both)
TODO: Submit upstream; drop once a release includes the fix.

--- pyutil/platformutil.py.orig	2026-05-30 07:27:01 UTC
+++ pyutil/platformutil.py
@@ -47,7 +47,7 @@ def get_linux_distro():
         return (_distname, _version)
 
     try:
-        etclsbrel = open("/etc/lsb-release", "rU")
+        etclsbrel = open("/etc/lsb-release")
         for line in etclsbrel:
             m = _distributor_id_file_re.search(line)
             if m:
@@ -62,7 +62,9 @@ def get_linux_distro():
     except EnvironmentError:
             pass
 
-    (_distname, _version) = platform.dist()[:2]
+    # platform.dist() was removed in Python 3.8
+    if hasattr(platform, "dist"):
+        (_distname, _version) = platform.dist()[:2]
     if _distname and _version:
         return (_distname, _version)
 
