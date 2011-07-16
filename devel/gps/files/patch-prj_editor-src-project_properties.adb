--- prj_editor/src/project_properties.adb.orig	2010-12-14 23:30:31.000000000 +0100
+++ prj_editor/src/project_properties.adb
@@ -4925,7 +4925,7 @@
       then
          --  Some pages might not be visible though...
          P := Get_Nth_Project_Editor_Page
-           (Ed.Kernel, Page - Pages_From_XML_Count);
+           (Ed.Kernel, Page - Pages_From_XML_Count + 1);
       end if;
 
       if P /= null then
@@ -4934,7 +4934,7 @@
          begin
             Refresh
               (Page      => P,
-               Widget    => Ed.Pages (Page - Pages_From_XML_Count),
+               Widget    => Ed.Pages (Page - Pages_From_XML_Count + 1),
                Project   => Ed.Project,
                Languages => Languages.all);
             Free (Languages);
