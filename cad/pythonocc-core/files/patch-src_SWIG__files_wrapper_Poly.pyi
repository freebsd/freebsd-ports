--- src/SWIG_files/wrapper/Poly.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/Poly.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -423,9 +423,9 @@ class Poly_MakeLoops2D: ...
 
 # harray1 classes
 
-class Poly_HArray1OfTriangle(NCollection_Array1<Poly_Triangle>, Standard_Transient):
+class Poly_HArray1OfTriangle(Any, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<Poly_Triangle>: ...
+    def Array1(self) -> Any: ...
 
 # harray2 classes
 # hsequence classes
