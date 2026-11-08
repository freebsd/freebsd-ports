--- src/SWIG_files/wrapper/AppParCurves.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/AppParCurves.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -259,24 +259,24 @@ class AppParCurves_MultiBSpCurve(AppParCurves_MultiCur
 
 # harray1 classes
 
-class AppParCurves_HArray1OfConstraintCouple(NCollection_Array1<AppParCurves_ConstraintCouple>, Standard_Transient):
+class AppParCurves_HArray1OfConstraintCouple(AppParCurves_Array1OfConstraintCouple, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<AppParCurves_ConstraintCouple>: ...
+    def Array1(self) -> AppParCurves_Array1OfConstraintCouple: ...
 
 
-class AppParCurves_HArray1OfMultiBSpCurve(NCollection_Array1<AppParCurves_MultiBSpCurve>, Standard_Transient):
+class AppParCurves_HArray1OfMultiBSpCurve(AppParCurves_Array1OfMultiBSpCurve, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<AppParCurves_MultiBSpCurve>: ...
+    def Array1(self) -> AppParCurves_Array1OfMultiBSpCurve: ...
 
 
-class AppParCurves_HArray1OfMultiCurve(NCollection_Array1<AppParCurves_MultiCurve>, Standard_Transient):
+class AppParCurves_HArray1OfMultiCurve(AppParCurves_Array1OfMultiCurve, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<AppParCurves_MultiCurve>: ...
+    def Array1(self) -> AppParCurves_Array1OfMultiCurve: ...
 
 
-class AppParCurves_HArray1OfMultiPoint(NCollection_Array1<AppParCurves_MultiPoint>, Standard_Transient):
+class AppParCurves_HArray1OfMultiPoint(AppParCurves_Array1OfMultiPoint, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<AppParCurves_MultiPoint>: ...
+    def Array1(self) -> AppParCurves_Array1OfMultiPoint: ...
 
 # harray2 classes
 # hsequence classes
