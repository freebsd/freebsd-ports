--- src/SWIG_files/wrapper/FEmTool.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/FEmTool.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -69,12 +69,12 @@ class FEmTool_SparseMatrix: ...
 # harray1 classes
 # harray2 classes
 
-class FEmTool_HAssemblyTable(NCollection_Array2<opencascade::handle<TColStd_HArray1OfInteger>>, Standard_Transient):
+class FEmTool_HAssemblyTable(Any, Standard_Transient):
     @overload
     def __init__(self, theRowLow: int, theRowUpp: int, theColLow: int, theColUpp: int) -> None: ...
     @overload
-    def __init__(self, theOther: NCollection_Array2<opencascade::handle<TColStd_HArray1OfInteger>>) -> None: ...
-    def Array2(self) -> NCollection_Array2<opencascade::handle<TColStd_HArray1OfInteger>>: ...
+    def __init__(self, theOther: Any) -> None: ...
+    def Array2(self) -> Any: ...
 
 # hsequence classes
 
