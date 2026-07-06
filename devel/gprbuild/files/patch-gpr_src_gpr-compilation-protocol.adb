  Fix compilation error:
  gpr-compilation-protocol.adb: error: "To_Unix_Time_64" not declared in "Conversions"
  Patch manually duplicated from Ravenports.

--- gpr/src/gpr-compilation-protocol.adb.orig	2026-06-22 00:11:44 UTC
+++ gpr/src/gpr-compilation-protocol.adb
@@ -22,7 +22,7 @@ ------------------------------------------------------
 --                                                                          --
 ------------------------------------------------------------------------------
 
-with Ada.Calendar.Conversions;   use Ada.Calendar;
+with Ada.Calendar.Time_Zones;    use Ada.Calendar;
 with Ada.Calendar.Formatting;    use Ada.Calendar.Formatting;
 with Ada.Characters.Handling;
 with Ada.Directories;            use Ada.Directories;
@@ -971,18 +971,29 @@ package body GPR.Compilation.Protocol is
    procedure Set_File_Stamp
      (Path_Name : String; Time_Stamp : Time_Stamp_Type)
    is
-      function TS (First, Last : Positive) return Integer is
-        (Integer'Value (String (Time_Stamp (First .. Last))));
-      --  Converts substring from Time_Stamp to Integer
+      use type Time_Zones.Time_Offset;
+
+      TS : constant String (Time_Stamp_Type'Range) := String (Time_Stamp);
+
+      T  : constant Time :=
+       Time_Of (Year      => Year_Number'Value (TS (1 .. 4)),
+                Month     => Month_Number'Value (TS (5 .. 6)),
+                Day       => Day_Number'Value (TS (7 .. 8)),
+                Hour      => Hour_Number'Value (TS (9 .. 10)),
+                Minute    => Minute_Number'Value (TS (11 .. 12)),
+                Second    => Second_Number'Value (TS (13 .. 14)),
+                Time_Zone => -Time_Zones.UTC_Time_Offset);
+   --  Time_Zone is negative to translate the UTC Time_Stamp to local time
    begin
       Set_File_Last_Modify_Time_Stamp
         (Path_Name,
-         To_Ada
-           (Long_Long_Integer
-              (Conversions.To_Unix_Time_64
-                 (Time_Of
-                    (TS (1, 4), TS (5, 6), TS (7, 8),
-                     TS (9, 10), TS (11, 12), TS (13, 14))))));
+          GM_Time_Of
+            (Year   => Formatting.Year (T),
+             Month  => Formatting.Month (T),
+             Day    => Formatting.Day (T),
+             Hour   => Formatting.Hour (T),
+             Minute => Formatting.Minute (T),
+             Second => Formatting.Second (T)));
    end Set_File_Stamp;
 
    -----------------------
