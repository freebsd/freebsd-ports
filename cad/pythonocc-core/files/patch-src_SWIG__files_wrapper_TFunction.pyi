--- src/SWIG_files/wrapper/TFunction.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/TFunction.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -209,9 +209,9 @@ class TFunction_Scope(TDF_Attribute):
 
 # harray1 classes
 
-class TFunction_HArray1OfDataMapOfGUIDDriver(NCollection_Array1<TFunction_DataMapOfGUIDDriver>, Standard_Transient):
+class TFunction_HArray1OfDataMapOfGUIDDriver(Any, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<TFunction_DataMapOfGUIDDriver>: ...
+    def Array1(self) -> Any: ...
 
 # harray2 classes
 # hsequence classes
