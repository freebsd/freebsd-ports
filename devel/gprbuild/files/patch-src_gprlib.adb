The brain-dead handling of Rpath continues in GPRBuild 2014
Bring in the GPRBuild 2012/2013 fix again

--- src/gprlib.adb.orig	2014-04-17 09:50:17.000000000 +0000
+++ src/gprlib.adb
@@ -408,6 +408,11 @@ procedure Gprlib is
 
    Separate_Run_Path_Options : Boolean := False;
 
+      Rpath_Disabled : Boolean := False;
+      --  If -R is passed through the library options for the linker, it will
+      --  prevent the implemented libraries portion of the rpath switch from
+      --  being built, even if the linker is capable of supporting rpath.
+
    Rpath : String_List_Access := null;
    --  Allocated only if Path Option is supported
 
@@ -1040,7 +1045,12 @@ begin
                   Use_GNAT_Lib := False;
                end if;
 
-               Library_Options_Table.Append (new String'(Line (1 .. Last)));
+               if Line (1 .. Last) = "-R" then
+                  Rpath_Disabled := True;
+               else
+                  Library_Options_Table.Append
+                    (new String'(Line (1 .. Last)));
+               end if;
 
             when Gprexch.Library_Rpath_Options =>
                Library_Rpath_Options_Table.Append
@@ -2166,7 +2176,7 @@ begin
          Library_Switches_Table.Append
            (new String'("-L" & Imported_Library_Directories.Table (J).all));
 
-         if Path_Option /= null then
+         if not Rpath_Disabled and then Path_Option /= null then
             Add_Rpath (Imported_Library_Directories.Table (J));
          end if;
 
