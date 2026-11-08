--- src/SWIG_files/wrapper/MeshVS.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/MeshVS.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -497,9 +497,9 @@ class MeshVS_VectorPrsBuilder(MeshVS_PrsBuilder):
 
 # harray1 classes
 
-class MeshVS_HArray1OfSequenceOfInteger(NCollection_Array1<TColStd_SequenceOfInteger>, Standard_Transient):
+class MeshVS_HArray1OfSequenceOfInteger(MeshVS_Array1OfSequenceOfInteger, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<TColStd_SequenceOfInteger>: ...
+    def Array1(self) -> MeshVS_Array1OfSequenceOfInteger: ...
 
 # harray2 classes
 # hsequence classes
