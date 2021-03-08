--- sipbuild/project.py.orig	2021-02-25 12:33:48 UTC
+++ sipbuild/project.py
@@ -335,9 +335,9 @@ class Project(AbstractProject, Configurable):
             generator=None, wheel_tag=None):
         """ Return a sequence of command line arguments to invoke sip-distinfo.
         """
-
+        flavor = '{}-{}.{}'.format(sip_distinfo, self.py_major_version, self.py_minor_version)
         args = [
-            sip_distinfo,
+            flavor,
 
             '--inventory',
             inventory,
