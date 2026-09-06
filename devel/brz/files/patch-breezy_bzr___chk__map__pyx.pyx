--- breezy/bzr/_chk_map_pyx.pyx.orig	2026-09-06 21:14:33 UTC
+++ breezy/bzr/_chk_map_pyx.pyx
@@ -40,8 +40,8 @@ from cpython.dict cimport (
 from cpython.dict cimport (
     PyDict_SetItem,
     )
-from cpython.int cimport (
-    PyInt_AsUnsignedLongMask,
+from cpython.long cimport (
+    PyLong_AsUnsignedLongMask,
     )
 from cpython.object cimport (
     PyObject,
@@ -102,7 +102,7 @@ def _search_key_16(key):
         if i > 0:
             c_out[0] = c'\x00'
             c_out = c_out + 1
-        crc_val = PyInt_AsUnsignedLongMask(crc32(key[i])) & 0xFFFFFFFFUL
+        crc_val = PyLong_AsUnsignedLongMask(crc32(key[i])) & 0xFFFFFFFFUL
         # Hex(val) order
         sprintf(c_out, '%08lX', crc_val)
         c_out = c_out + 8
@@ -127,7 +127,7 @@ def _search_key_255(key):
         if i > 0:
             c_out[0] = c'\x00'
             c_out = c_out + 1
-        crc_val = PyInt_AsUnsignedLongMask(crc32(key[i]))
+        crc_val = PyLong_AsUnsignedLongMask(crc32(key[i]))
         # MSB order
         c_out[0] = (crc_val >> 24) & 0xFF
         c_out[1] = (crc_val >> 16) & 0xFF
