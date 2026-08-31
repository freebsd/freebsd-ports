--- src/SWIG_files/wrapper/TransferBRep.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/TransferBRep.pyi
@@ -1,5 +1,5 @@ from enum import IntEnum
 from enum import IntEnum
-from typing import overload, NewType, Optional, Tuple
+from typing import Any, overload, NewType, Optional, Tuple
 
 from OCC.Core.Standard import *
 from OCC.Core.NCollection import *
@@ -178,12 +178,12 @@ class TransferBRep_ShapeBinder(TransferBRep_BinderOfSh
 # harray2 classes
 # hsequence classes
 
-class TransferBRep_HSequenceOfTransferResultInfo(NCollection_Sequence<opencascade::handle<TransferBRep_TransferResultInfo>>, Standard_Transient):
+class TransferBRep_HSequenceOfTransferResultInfo(TransferBRep_SequenceOfTransferResultInfo, Standard_Transient):
     @overload
     def __init__(self) -> None: ...
     @overload
-    def __init__(self, other: NCollection_Sequence<opencascade::handle<TransferBRep_TransferResultInfo>>) -> None: ...
-    def Sequence(self) -> NCollection_Sequence<opencascade::handle<TransferBRep_TransferResultInfo>>: ...
-    def Append(self, theSequence: NCollection_Sequence<opencascade::handle<TransferBRep_TransferResultInfo>>) -> None: ...
+    def __init__(self, other: TransferBRep_SequenceOfTransferResultInfo) -> None: ...
+    def Sequence(self) -> TransferBRep_SequenceOfTransferResultInfo: ...
+    def Append(self, theSequence: TransferBRep_SequenceOfTransferResultInfo) -> None: ...
 
 
