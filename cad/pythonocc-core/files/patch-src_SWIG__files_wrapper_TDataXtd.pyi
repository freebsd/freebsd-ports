--- src/SWIG_files/wrapper/TDataXtd.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/TDataXtd.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -462,9 +462,9 @@ class TDataXtd_PatternStd(TDataXtd_Pattern):
 
 # harray1 classes
 
-class TDataXtd_HArray1OfTrsf(NCollection_Array1<gp_Trsf>, Standard_Transient):
+class TDataXtd_HArray1OfTrsf(TDataXtd_Array1OfTrsf, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<gp_Trsf>: ...
+    def Array1(self) -> TDataXtd_Array1OfTrsf: ...
 
 # harray2 classes
 # hsequence classes
