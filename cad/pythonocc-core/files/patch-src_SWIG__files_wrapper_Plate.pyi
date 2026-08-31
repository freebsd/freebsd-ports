--- src/SWIG_files/wrapper/Plate.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/Plate.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -218,9 +218,9 @@ class Plate_SampledCurveConstraint:
 
 # harray1 classes
 
-class Plate_HArray1OfPinpointConstraint(NCollection_Array1<Plate_PinpointConstraint>, Standard_Transient):
+class Plate_HArray1OfPinpointConstraint(Plate_Array1OfPinpointConstraint, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<Plate_PinpointConstraint>: ...
+    def Array1(self) -> Plate_Array1OfPinpointConstraint: ...
 
 # harray2 classes
 # hsequence classes
