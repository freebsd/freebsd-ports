--- prj_editor/src/project_viewers.ads.orig	2010-12-14 23:30:31.000000000 +0100
+++ prj_editor/src/project_viewers.ads
@@ -159,7 +159,7 @@
    --  Return the number of registered project editor pages
 
    function Get_Nth_Project_Editor_Page
-     (Kernel : access GPS.Kernel.Kernel_Handle_Record'Class; Num : Natural)
+     (Kernel : access GPS.Kernel.Kernel_Handle_Record'Class; Num : Positive)
       return Project_Editor_Page;
    --  Return the Num-th registered project editor page.
    --  First page is number 1.
