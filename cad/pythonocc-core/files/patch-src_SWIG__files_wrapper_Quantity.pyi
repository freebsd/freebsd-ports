--- src/SWIG_files/wrapper/Quantity.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/Quantity.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -1263,9 +1263,9 @@ class Quantity_Period:
 
 # harray1 classes
 
-class Quantity_HArray1OfColor(NCollection_Array1<Quantity_Color>, Standard_Transient):
+class Quantity_HArray1OfColor(Quantity_Array1OfColor, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<Quantity_Color>: ...
+    def Array1(self) -> Quantity_Array1OfColor: ...
 
 # harray2 classes
 # hsequence classes
