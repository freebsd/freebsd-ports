--- par-ch5.adb.orig	Fri Sep  1 10:13:57 2000
+++ par-ch5.adb	Fri Feb  8 21:15:01 2002
@@ -1006,7 +1006,7 @@
 
    --  Error recovery: can raise Error_Resync
 
-   function P_Assignment_Statement (Lhs : Node_Id) return Node_Id is
+   function P_Assignment_Statement (LHS : Node_Id) return Node_Id is
       Assign_Node : Node_Id;
 
    begin
