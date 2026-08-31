--- src/SWIG_files/wrapper/StepData.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/StepData.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -622,9 +622,9 @@ class StepData_UndefinedEntity: ...
 
 # harray1 classes
 
-class StepData_HArray1OfField(NCollection_Array1<StepData_Field>, Standard_Transient):
+class StepData_HArray1OfField(StepData_Array1OfField, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<StepData_Field>: ...
+    def Array1(self) -> StepData_Array1OfField: ...
 
 # harray2 classes
 # hsequence classes
