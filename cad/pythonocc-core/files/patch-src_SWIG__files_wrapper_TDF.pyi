--- src/SWIG_files/wrapper/TDF.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/TDF.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -617,9 +617,9 @@ class TDF_DerivedAttribute: ...
 
 # harray1 classes
 
-class TDF_HAttributeArray1(NCollection_Array1<opencascade::handle<TDF_Attribute>>, Standard_Transient):
+class TDF_HAttributeArray1(TDF_AttributeArray1, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<opencascade::handle<TDF_Attribute>>: ...
+    def Array1(self) -> TDF_AttributeArray1: ...
 
 # harray2 classes
 # hsequence classes
