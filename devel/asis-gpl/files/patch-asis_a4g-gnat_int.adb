--- asis/a4g-gnat_int.adb.orig	Mon Jan  1 01:18:22 2007
+++ asis/a4g-gnat_int.adb	Mon Jan  1 01:18:54 2007
@@ -72,7 +72,7 @@
 
    LT           : String renames ASIS_Line_Terminator;
    Standard_GCC : constant String_Access :=
-     GNAT.OS_Lib.Locate_Exec_On_Path ("gcc");
+     GNAT.OS_Lib.Locate_Exec_On_Path ("gnatgcc");
 
    -----------------
    -- Create_Tree --
