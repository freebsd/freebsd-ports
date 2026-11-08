--- src/SWIG_files/wrapper/BRepAdaptor.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/BRepAdaptor.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -120,9 +120,9 @@ class BRepAdaptor_Surface(GeomAdaptor_TransformedSurfa
 
 # harray1 classes
 
-class BRepAdaptor_HArray1OfCurve(NCollection_Array1<BRepAdaptor_Curve>, Standard_Transient):
+class BRepAdaptor_HArray1OfCurve(BRepAdaptor_Array1OfCurve, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<BRepAdaptor_Curve>: ...
+    def Array1(self) -> BRepAdaptor_Array1OfCurve: ...
 
 # harray2 classes
 # hsequence classes
