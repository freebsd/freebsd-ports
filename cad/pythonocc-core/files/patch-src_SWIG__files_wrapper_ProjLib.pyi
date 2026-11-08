--- src/SWIG_files/wrapper/ProjLib.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/ProjLib.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -434,12 +434,12 @@ class ProjLib_Torus(ProjLib_Projector):
 # harray2 classes
 # hsequence classes
 
-class ProjLib_HSequenceOfHSequenceOfPnt(NCollection_Sequence<opencascade::handle<TColgp_HSequenceOfPnt>>, Standard_Transient):
+class ProjLib_HSequenceOfHSequenceOfPnt(ProjLib_SequenceOfHSequenceOfPnt, Standard_Transient):
     @overload
     def __init__(self) -> None: ...
     @overload
-    def __init__(self, other: NCollection_Sequence<opencascade::handle<TColgp_HSequenceOfPnt>>) -> None: ...
-    def Sequence(self) -> NCollection_Sequence<opencascade::handle<TColgp_HSequenceOfPnt>>: ...
-    def Append(self, theSequence: NCollection_Sequence<opencascade::handle<TColgp_HSequenceOfPnt>>) -> None: ...
+    def __init__(self, other: ProjLib_SequenceOfHSequenceOfPnt) -> None: ...
+    def Sequence(self) -> ProjLib_SequenceOfHSequenceOfPnt: ...
+    def Append(self, theSequence: ProjLib_SequenceOfHSequenceOfPnt) -> None: ...
 
 
