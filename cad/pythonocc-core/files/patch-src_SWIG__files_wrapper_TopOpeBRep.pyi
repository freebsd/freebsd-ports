--- src/SWIG_files/wrapper/TopOpeBRep.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/TopOpeBRep.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -635,14 +635,14 @@ class TopOpeBRep_traceSIFF: ...
 
 # harray1 classes
 
-class TopOpeBRep_HArray1OfLineInter(NCollection_Array1<TopOpeBRep_LineInter>, Standard_Transient):
+class TopOpeBRep_HArray1OfLineInter(TopOpeBRep_Array1OfLineInter, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<TopOpeBRep_LineInter>: ...
+    def Array1(self) -> TopOpeBRep_Array1OfLineInter: ...
 
 
-class TopOpeBRep_HArray1OfVPointInter(NCollection_Array1<TopOpeBRep_VPointInter>, Standard_Transient):
+class TopOpeBRep_HArray1OfVPointInter(TopOpeBRep_Array1OfVPointInter, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<TopOpeBRep_VPointInter>: ...
+    def Array1(self) -> TopOpeBRep_Array1OfVPointInter: ...
 
 # harray2 classes
 # hsequence classes
