--- src/SWIG_files/wrapper/Geom.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/Geom.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -1239,12 +1239,12 @@ class Geom_TrimmedCurve(Geom_BoundedCurve):
 # harray2 classes
 # hsequence classes
 
-class Geom_HSequenceOfBSplineSurface(NCollection_Sequence<opencascade::handle<Geom_BSplineSurface>>, Standard_Transient):
+class Geom_HSequenceOfBSplineSurface(Geom_SequenceOfBSplineSurface, Standard_Transient):
     @overload
     def __init__(self) -> None: ...
     @overload
-    def __init__(self, other: NCollection_Sequence<opencascade::handle<Geom_BSplineSurface>>) -> None: ...
-    def Sequence(self) -> NCollection_Sequence<opencascade::handle<Geom_BSplineSurface>>: ...
-    def Append(self, theSequence: NCollection_Sequence<opencascade::handle<Geom_BSplineSurface>>) -> None: ...
+    def __init__(self, other: Geom_SequenceOfBSplineSurface) -> None: ...
+    def Sequence(self) -> Geom_SequenceOfBSplineSurface: ...
+    def Append(self, theSequence: Geom_SequenceOfBSplineSurface) -> None: ...
 
 
