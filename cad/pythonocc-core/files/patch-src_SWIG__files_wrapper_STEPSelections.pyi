--- src/SWIG_files/wrapper/STEPSelections.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/STEPSelections.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -124,12 +124,12 @@ class STEPSelections_SelectInstances(IFSelect_SelectEx
 # harray2 classes
 # hsequence classes
 
-class STEPSelections_HSequenceOfAssemblyLink(NCollection_Sequence<opencascade::handle<STEPSelections_AssemblyLink>>, Standard_Transient):
+class STEPSelections_HSequenceOfAssemblyLink(STEPSelections_SequenceOfAssemblyLink, Standard_Transient):
     @overload
     def __init__(self) -> None: ...
     @overload
-    def __init__(self, other: NCollection_Sequence<opencascade::handle<STEPSelections_AssemblyLink>>) -> None: ...
-    def Sequence(self) -> NCollection_Sequence<opencascade::handle<STEPSelections_AssemblyLink>>: ...
-    def Append(self, theSequence: NCollection_Sequence<opencascade::handle<STEPSelections_AssemblyLink>>) -> None: ...
+    def __init__(self, other: STEPSelections_SequenceOfAssemblyLink) -> None: ...
+    def Sequence(self) -> STEPSelections_SequenceOfAssemblyLink: ...
+    def Append(self, theSequence: STEPSelections_SequenceOfAssemblyLink) -> None: ...
 
 
