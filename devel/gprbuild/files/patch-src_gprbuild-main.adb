It seems GNAT Pro makeutl.adb renamed an argument which hasn't trickled
back to FSF GCC yet.

--- src/gprbuild-main.adb.orig	2014-04-17 09:50:17.000000000 +0000
+++ src/gprbuild-main.adb
@@ -2099,7 +2099,7 @@ begin
 
    Do_Compute_Builder_Switches
      (Project_Tree     => Project_Tree,
-      Env              => Root_Environment,
+      Root_Environment => Root_Environment,
       Main_Project     => Main_Project);
 
    Queue.Initialize (Opt.One_Compilation_Per_Obj_Dir);
