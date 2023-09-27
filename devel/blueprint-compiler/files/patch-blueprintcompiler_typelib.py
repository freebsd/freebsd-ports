--- blueprintcompiler/typelib.py.orig	2023-07-21 20:06:18 UTC
+++ blueprintcompiler/typelib.py
@@ -61,7 +61,14 @@ class Field:
     def __init__(self, offset: int, type: str, shift=0, mask=None):
         self._offset = offset
         self._type = type
-        self._shift = shift
+        if not mask or sys.byteorder == "little":
+            self._shift = shift
+        elif self._type == "u8" or self._type == "i8":
+            self._shift = 8 - (shift + mask)
+        elif self._type == "u16" or self._type == "i16":
+            self._shift = 16 - (shift + mask)
+        else:
+            self._shift = 32 - (shift + mask)
         self._mask = (1 << mask) - 1 if mask else None
         self._name = f"{offset}__{type}__{shift}__{mask}"
 
@@ -170,7 +177,7 @@ class Typelib:
     OBJ_FINAL = Field(0x02, "u16", 3, 1)
     OBJ_GTYPE_NAME = Field(0x08, "string")
     OBJ_PARENT = Field(0x10, "dir_entry")
-    OBJ_GTYPE_STRUCT = Field(0x14, "string")
+    OBJ_GTYPE_STRUCT = Field(0x12, "string")
     OBJ_N_INTERFACES = Field(0x14, "u16")
     OBJ_N_FIELDS = Field(0x16, "u16")
     OBJ_N_PROPERTIES = Field(0x18, "u16")
@@ -255,7 +262,9 @@ class Typelib:
 
     def _int(self, size, signed) -> int:
         return int.from_bytes(
-            self._typelib_file[self._offset : self._offset + size], sys.byteorder
+            self._typelib_file[self._offset : self._offset + size],
+            sys.byteorder,
+            signed=signed,
         )
 
 
