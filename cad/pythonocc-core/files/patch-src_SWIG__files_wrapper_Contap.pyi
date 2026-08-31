--- src/SWIG_files/wrapper/Contap.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/Contap.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -456,12 +456,12 @@ class Contap_TheSegmentOfTheSearch:
 # harray2 classes
 # hsequence classes
 
-class Contap_TheHSequenceOfPoint(NCollection_Sequence<Contap_Point>, Standard_Transient):
+class Contap_TheHSequenceOfPoint(Contap_TheSequenceOfPoint, Standard_Transient):
     @overload
     def __init__(self) -> None: ...
     @overload
-    def __init__(self, other: NCollection_Sequence<Contap_Point>) -> None: ...
-    def Sequence(self) -> NCollection_Sequence<Contap_Point>: ...
-    def Append(self, theSequence: NCollection_Sequence<Contap_Point>) -> None: ...
+    def __init__(self, other: Contap_TheSequenceOfPoint) -> None: ...
+    def Sequence(self) -> Contap_TheSequenceOfPoint: ...
+    def Append(self, theSequence: Contap_TheSequenceOfPoint) -> None: ...
 
 
