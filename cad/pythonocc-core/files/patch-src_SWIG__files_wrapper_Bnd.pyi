--- src/SWIG_files/wrapper/Bnd.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/Bnd.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -337,19 +337,19 @@ class Bnd_Tools:
 
 # harray1 classes
 
-class Bnd_HArray1OfBox(NCollection_Array1<Bnd_Box>, Standard_Transient):
+class Bnd_HArray1OfBox(Bnd_Array1OfBox, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<Bnd_Box>: ...
+    def Array1(self) -> Bnd_Array1OfBox: ...
 
 
-class Bnd_HArray1OfBox2d(NCollection_Array1<Bnd_Box2d>, Standard_Transient):
+class Bnd_HArray1OfBox2d(Bnd_Array1OfBox2d, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<Bnd_Box2d>: ...
+    def Array1(self) -> Bnd_Array1OfBox2d: ...
 
 
-class Bnd_HArray1OfSphere(NCollection_Array1<Bnd_Sphere>, Standard_Transient):
+class Bnd_HArray1OfSphere(Bnd_Array1OfSphere, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<Bnd_Sphere>: ...
+    def Array1(self) -> Bnd_Array1OfSphere: ...
 
 # harray2 classes
 # hsequence classes
