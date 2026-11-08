-- Load XML strings via a temporary file instead of lf_db_load_data()
-- lensfun 0.3.95 declares lf_db_load_data() with an errcontext argument in the
-- header but implements it without, so the C symbol doesn't exist and importing fails

--- lensfunpy/_lensfun.pyx.orig	2026-10-18 19:11:12 UTC
+++ lensfunpy/_lensfun.pyx
@@ -6,6 +6,7 @@ import glob
 
 import os
 import glob
+import tempfile
 from enum import Enum, IntEnum
 from collections import namedtuple
 
@@ -262,8 +263,12 @@ cdef class Database:
             handleError(lf_db_load_file(self.lf, _chars(path)))
 
         if xml:
-            xml = _chars(xml.strip()) # stripping as lensfun is very strict here
-            handleError(lf_db_load_data(self.lf, 'XML', xml, len(xml)))
+            xml = xml.strip() # stripping as lensfun is very strict here
+            with tempfile.TemporaryDirectory() as tmpdir:
+                xml_path = os.path.join(tmpdir, 'data.xml')
+                with open(xml_path, 'w', encoding='utf-8') as f:
+                    f.write(xml)
+                handleError(lf_db_load_file(self.lf, _chars(xml_path)))
 
 
     def __dealloc__(self):
