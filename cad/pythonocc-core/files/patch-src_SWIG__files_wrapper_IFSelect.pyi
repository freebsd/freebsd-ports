--- src/SWIG_files/wrapper/IFSelect.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/IFSelect.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -1213,12 +1213,12 @@ class IFSelect_SelectType(IFSelect_SelectAnyType):
 # harray2 classes
 # hsequence classes
 
-class IFSelect_HSeqOfSelection(NCollection_Sequence<opencascade::handle<IFSelect_Selection>>, Standard_Transient):
+class IFSelect_HSeqOfSelection(IFSelect_TSeqOfSelection, Standard_Transient):
     @overload
     def __init__(self) -> None: ...
     @overload
-    def __init__(self, other: NCollection_Sequence<opencascade::handle<IFSelect_Selection>>) -> None: ...
-    def Sequence(self) -> NCollection_Sequence<opencascade::handle<IFSelect_Selection>>: ...
-    def Append(self, theSequence: NCollection_Sequence<opencascade::handle<IFSelect_Selection>>) -> None: ...
+    def __init__(self, other: IFSelect_TSeqOfSelection) -> None: ...
+    def Sequence(self) -> IFSelect_TSeqOfSelection: ...
+    def Append(self, theSequence: IFSelect_TSeqOfSelection) -> None: ...
 
 
