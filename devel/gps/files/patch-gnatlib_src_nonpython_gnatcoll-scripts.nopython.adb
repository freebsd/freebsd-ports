--- gnatlib/src/nopython/gnatcoll-scripts-python.adb.orig	2011-10-09 05:02:49.000000000 +0200
+++ gnatlib/src/nopython/gnatcoll-scripts-python.adb	2011-10-09 05:13:08.000000000 +0200
@@ -33,9 +33,11 @@
 
    procedure Register_Python_Scripting
      (Repo          : Scripts.Scripts_Repository;
-      Module        : String)
+      Module        : String;
+      Program_Name  : String := "python";
+      Python_Home   : String := "")
    is
-      pragma Unreferenced (Repo, Module);
+      pragma Unreferenced (Repo, Module, Program_Name, Python_Home);
    begin
       null;
    end Register_Python_Scripting;
