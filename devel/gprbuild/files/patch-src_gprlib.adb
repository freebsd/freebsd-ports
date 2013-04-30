$NetBSD: patch-src_gprlib.adb,v 1.1 2012/07/08 20:08:42 marino Exp $

--- src/gprlib.adb.orig	2012-05-10 13:59:05.000000000 +0000
+++ src/gprlib.adb
@@ -390,6 +390,11 @@ procedure Gprlib is
 
    Separate_Run_Path_Options : Boolean := False;
 
+      Rpath_Disabled : Boolean := False;
+      --  If -R is passed through the library options for the linker, it will
+      --  prevent the implemented libraries portion of the rpath switch from
+      --  being built, even if the linker is capable of supporting rpath.
+
    Rpath : String_List_Access := null;
    --  Allocated only if Path Option is supported
 
@@ -1009,7 +1014,12 @@ begin
                   Use_GNAT_Lib := False;
                end if;
 
-               Library_Options_Table.Append (new String'(Line (1 .. Last)));
+               if Line (1 .. Last) = "-R" then
+                  Rpath_Disabled := True;
+               else
+                  Library_Options_Table.Append
+                    (new String'(Line (1 .. Last)));
+               end if;
 
             when Library_Path =>
                Osint.Fail ("library path should not be specified");
@@ -2127,7 +2137,7 @@ begin
          Library_Switches_Table.Append
            (new String'("-L" & Imported_Library_Directories.Table (J).all));
 
-         if Path_Option /= null then
+         if not Rpath_Disabled and then Path_Option /= null then
             Add_Rpath (Imported_Library_Directories.Table (J));
          end if;
 
