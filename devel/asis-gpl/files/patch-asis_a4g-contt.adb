--- asis/a4g-contt.adb.orig	Mon Jan  1 01:58:28 2007
+++ asis/a4g-contt.adb	Mon Jan  1 02:06:19 2007
@@ -973,7 +973,7 @@
                if Dash_Idx > 0 then
                   Contexts.Table (Cont).GCC :=
                     Locate_Exec_On_Path
-                      (Tool_Name (Tool_Name'First .. Dash_Idx) & "gcc");
+                      (Tool_Name (Tool_Name'First .. Dash_Idx) & "gnatgcc");
                end if;
 
             end;
