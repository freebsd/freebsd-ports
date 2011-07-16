--- prj_editor/src/project_viewers.adb.orig	2010-12-14 23:30:31.000000000 +0100
+++ prj_editor/src/project_viewers.adb
@@ -1657,7 +1657,7 @@
    ---------------------------------
 
    function Get_Nth_Project_Editor_Page
-     (Kernel : access Kernel_Handle_Record'Class; Num : Natural)
+     (Kernel : access Kernel_Handle_Record'Class; Num : Positive)
       return Project_Editor_Page
    is
       pragma Unreferenced (Kernel);
