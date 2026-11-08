--- src/SWIG_files/wrapper/TopOpeBRepDS.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/TopOpeBRepDS.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -875,9 +875,9 @@ class TopOpeBRepDS_HDataStructure: ...
 
 # harray1 classes
 
-class TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference(NCollection_Array1<TopOpeBRepDS_DataMapOfIntegerListOfInterference>, Standard_Transient):
+class TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference(Any, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<TopOpeBRepDS_DataMapOfIntegerListOfInterference>: ...
+    def Array1(self) -> Any: ...
 
 # harray2 classes
 # hsequence classes
