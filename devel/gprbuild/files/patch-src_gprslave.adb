Set_File_Last_Modify_Time_Stamp has been added to GNAT.OS_Lib on GNAT Pro
but that hasn't made it to gcc 4.9 yet.  For the moment, just disable the
set file timestamp functionality that it serves here.

--- src/gprslave.adb.orig	2014-04-17 09:50:17.000000000 +0000
+++ src/gprslave.adb
@@ -1261,17 +1261,8 @@ procedure Gprslave is
          procedure Set_Stamp
            (Path_Name : String; Time_Stamp : Time_Stamp_Type)
          is
-            TS : constant String := String (Time_Stamp);
          begin
-            Set_File_Last_Modify_Time_Stamp
-              (Path_Name,
-               GM_Time_Of
-                 (Year   => Year_Type'Value (TS (1 .. 4)),
-                  Month  => Month_Type'Value (TS (5 .. 6)),
-                  Day    => Day_Type'Value (TS (7 .. 8)),
-                  Hour   => Hour_Type'Value (TS (9 .. 10)),
-                  Minute => Minute_Type'Value (TS (11 .. 12)),
-                  Second => Second_Type'Value (TS (13 .. 14))));
+            pragma Unreferenced (Path_Name, Time_Stamp);
          end Set_Stamp;
 
          ------------------
