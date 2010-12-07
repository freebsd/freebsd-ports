
$FreeBSD$

--- lib/Target/X86/X86ISelLowering.cpp.orig
+++ lib/Target/X86/X86ISelLowering.cpp
@@ -5414,11 +5414,19 @@
     return getMOVL(DAG, dl, VT, V2, V1);
   }
 
-  if (X86::isUNPCKL_v_undef_Mask(SVOp) || X86::isUNPCKLMask(SVOp))
+  if (X86::isUNPCKL_v_undef_Mask(SVOp))
+    return (isMMX) ?
+      Op : getTargetShuffleNode(getUNPCKLOpcode(VT), dl, VT, V1, V1, DAG);
+
+  if (X86::isUNPCKLMask(SVOp))
     return (isMMX) ?
       Op : getTargetShuffleNode(getUNPCKLOpcode(VT), dl, VT, V1, V2, DAG);
 
-  if (X86::isUNPCKH_v_undef_Mask(SVOp) || X86::isUNPCKHMask(SVOp))
+  if (X86::isUNPCKH_v_undef_Mask(SVOp))
+    return (isMMX) ?
+      Op : getTargetShuffleNode(getUNPCKHOpcode(VT), dl, VT, V1, V1, DAG);
+
+  if (X86::isUNPCKHMask(SVOp))
     return (isMMX) ?
       Op : getTargetShuffleNode(getUNPCKHOpcode(VT), dl, VT, V1, V2, DAG);
 
