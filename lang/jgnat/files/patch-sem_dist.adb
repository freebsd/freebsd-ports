--- sem_dist.adb.orig	Fri Sep  1 10:14:00 2000
+++ sem_dist.adb	Fri Feb  8 21:38:20 2002
@@ -213,7 +213,7 @@
    -- Process_Partition_ID --
    --------------------------
 
-   procedure Process_Partition_ID (N : Node_Id) is
+   procedure Process_Partition_Id (N : Node_Id) is
       Loc            : constant Source_Ptr := Sloc (N);
       Ety            : Entity_Id;
       Nd             : Node_Id;
@@ -288,7 +288,7 @@
       Rewrite (N, Convert_To (Typ, Get_Pt_Id_Call));
       Analyze_And_Resolve (N, Typ);
 
-   end Process_Partition_ID;
+   end Process_Partition_Id;
 
    ----------------------------------
    -- Process_Remote_AST_Attribute --
