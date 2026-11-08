--- src/SWIG_files/wrapper/IGESData.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/IGESData.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -733,9 +733,9 @@ class IGESData_FreeFormatEntity(IGESData_UndefinedEnti
 
 # harray1 classes
 
-class IGESData_HArray1OfIGESEntity(NCollection_Array1<opencascade::handle<IGESData_IGESEntity>>, Standard_Transient):
+class IGESData_HArray1OfIGESEntity(IGESData_Array1OfIGESEntity, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<opencascade::handle<IGESData_IGESEntity>>: ...
+    def Array1(self) -> IGESData_Array1OfIGESEntity: ...
 
 # harray2 classes
 # hsequence classes
