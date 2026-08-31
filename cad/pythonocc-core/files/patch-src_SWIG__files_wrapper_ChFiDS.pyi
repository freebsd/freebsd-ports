--- src/SWIG_files/wrapper/ChFiDS.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/ChFiDS.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -597,19 +597,19 @@ class ChFiDS_FilSpine(ChFiDS_Spine):
 
 # harray1 classes
 
-class ChFiDS_SecHArray1(NCollection_Array1<ChFiDS_CircSection>, Standard_Transient):
+class ChFiDS_SecHArray1(ChFiDS_SecArray1, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<ChFiDS_CircSection>: ...
+    def Array1(self) -> ChFiDS_SecArray1: ...
 
 # harray2 classes
 # hsequence classes
 
-class ChFiDS_HData(NCollection_Sequence<opencascade::handle<ChFiDS_SurfData>>, Standard_Transient):
+class ChFiDS_HData(ChFiDS_SequenceOfSurfData, Standard_Transient):
     @overload
     def __init__(self) -> None: ...
     @overload
-    def __init__(self, other: NCollection_Sequence<opencascade::handle<ChFiDS_SurfData>>) -> None: ...
-    def Sequence(self) -> NCollection_Sequence<opencascade::handle<ChFiDS_SurfData>>: ...
-    def Append(self, theSequence: NCollection_Sequence<opencascade::handle<ChFiDS_SurfData>>) -> None: ...
+    def __init__(self, other: ChFiDS_SequenceOfSurfData) -> None: ...
+    def Sequence(self) -> ChFiDS_SequenceOfSurfData: ...
+    def Append(self, theSequence: ChFiDS_SequenceOfSurfData) -> None: ...
 
 
