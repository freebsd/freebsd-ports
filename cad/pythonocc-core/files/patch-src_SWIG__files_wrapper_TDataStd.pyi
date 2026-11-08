--- src/SWIG_files/wrapper/TDataStd.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/TDataStd.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -920,9 +920,9 @@ class TDataStd_GenericExtString: ...
 
 # harray1 classes
 
-class TDataStd_HLabelArray1(NCollection_Array1<TDF_Label>, Standard_Transient):
+class TDataStd_HLabelArray1(TDataStd_LabelArray1, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<TDF_Label>: ...
+    def Array1(self) -> TDataStd_LabelArray1: ...
 
 # harray2 classes
 # hsequence classes
