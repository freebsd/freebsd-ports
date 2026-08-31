--- src/SWIG_files/wrapper/AppDef.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/AppDef.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -521,9 +521,9 @@ class AppDef_LinearCriteria(AppDef_SmoothCriterion):
 
 # harray1 classes
 
-class AppDef_HArray1OfMultiPointConstraint(NCollection_Array1<AppDef_MultiPointConstraint>, Standard_Transient):
+class AppDef_HArray1OfMultiPointConstraint(AppDef_Array1OfMultiPointConstraint, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<AppDef_MultiPointConstraint>: ...
+    def Array1(self) -> AppDef_Array1OfMultiPointConstraint: ...
 
 # harray2 classes
 # hsequence classes
