--- sipbuild/project.py.orig	2025-11-12 11:53:43 UTC
+++ sipbuild/project.py
@@ -432,9 +432,9 @@ class Project(AbstractProject, Configurable):
             generator=None, wheel_tag=None, generator_version=None):
         """ Return a sequence of command line arguments to invoke sip-distinfo.
         """
-
+        flavor = '{}-{}.{}'.format(sip_distinfo, self.py_major_version, self.py_minor_version)
         args = [
-            sip_distinfo,
+            flavor,
 
             '--inventory',
             inventory,
