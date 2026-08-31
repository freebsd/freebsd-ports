--- src/SWIG_files/wrapper/MoniTool.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/MoniTool.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -292,12 +292,12 @@ class MoniTool_TransientElem(MoniTool_Element):
 # harray2 classes
 # hsequence classes
 
-class MoniTool_HSequenceOfElement(NCollection_Sequence<opencascade::handle<MoniTool_Element>>, Standard_Transient):
+class MoniTool_HSequenceOfElement(MoniTool_SequenceOfElement, Standard_Transient):
     @overload
     def __init__(self) -> None: ...
     @overload
-    def __init__(self, other: NCollection_Sequence<opencascade::handle<MoniTool_Element>>) -> None: ...
-    def Sequence(self) -> NCollection_Sequence<opencascade::handle<MoniTool_Element>>: ...
-    def Append(self, theSequence: NCollection_Sequence<opencascade::handle<MoniTool_Element>>) -> None: ...
+    def __init__(self, other: MoniTool_SequenceOfElement) -> None: ...
+    def Sequence(self) -> MoniTool_SequenceOfElement: ...
+    def Append(self, theSequence: MoniTool_SequenceOfElement) -> None: ...
 
 
