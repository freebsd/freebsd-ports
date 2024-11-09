--- sipbuild/project.py.orig	2024-07-12 11:20:17 UTC
+++ sipbuild/project.py
@@ -408,9 +408,9 @@ class Project(AbstractProject, Configurable):
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
