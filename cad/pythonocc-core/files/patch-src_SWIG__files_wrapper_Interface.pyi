--- src/SWIG_files/wrapper/Interface.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/Interface.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -1052,19 +1052,19 @@ class Interface_Static(Interface_TypedValue):
 
 # harray1 classes
 
-class Interface_HArray1OfHAsciiString(NCollection_Array1<opencascade::handle<TCollection_HAsciiString>>, Standard_Transient):
+class Interface_HArray1OfHAsciiString(Interface_Array1OfHAsciiString, Standard_Transient):
     def __init__(self, theLower: int, theUpper: int) -> None: ...
-    def Array1(self) -> NCollection_Array1<opencascade::handle<TCollection_HAsciiString>>: ...
+    def Array1(self) -> Interface_Array1OfHAsciiString: ...
 
 # harray2 classes
 # hsequence classes
 
-class Interface_HSequenceOfCheck(NCollection_Sequence<opencascade::handle<Interface_Check>>, Standard_Transient):
+class Interface_HSequenceOfCheck(Interface_SequenceOfCheck, Standard_Transient):
     @overload
     def __init__(self) -> None: ...
     @overload
-    def __init__(self, other: NCollection_Sequence<opencascade::handle<Interface_Check>>) -> None: ...
-    def Sequence(self) -> NCollection_Sequence<opencascade::handle<Interface_Check>>: ...
-    def Append(self, theSequence: NCollection_Sequence<opencascade::handle<Interface_Check>>) -> None: ...
+    def __init__(self, other: Interface_SequenceOfCheck) -> None: ...
+    def Sequence(self) -> Interface_SequenceOfCheck: ...
+    def Append(self, theSequence: Interface_SequenceOfCheck) -> None: ...
 
 
