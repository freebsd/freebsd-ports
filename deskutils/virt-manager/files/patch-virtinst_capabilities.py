--- virtinst/capabilities.py.orig	2015-05-31 18:53:44 UTC
+++ virtinst/capabilities.py
@@ -19,6 +19,8 @@
 # Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 # MA 02110-1301 USA.
 
+import logging
+import os
 import re
 
 from .cpu import CPU as DomainCPU
@@ -52,10 +54,15 @@ class _CPUMapFileValues(XMLBuilder):
     cpu_map.xml
     """
     # This is overwritten as part of the test suite
-    _cpu_filename = "/usr/share/libvirt/cpu_map.xml"
+    _cpu_filename = "/usr/local/share/libvirt/cpu_map.xml"
 
     def __init__(self, conn):
-        xml = file(self._cpu_filename).read()
+        if os.path.exists(self._cpu_filename):
+            xml = file(self._cpu_filename).read()
+        else:
+            xml = None
+            logging.debug("CPU map file not found: %s", self._cpu_filename)
+
         XMLBuilder.__init__(self, conn, parsexml=xml)
 
         self._archmap = {}
