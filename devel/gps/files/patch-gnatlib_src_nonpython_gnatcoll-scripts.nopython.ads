--- gnatlib/src/nopython/gnatcoll-scripts-python.ads.orig	2010-10-14 12:15:05.000000000 +0200
+++ gnatlib/src/nopython/gnatcoll-scripts-python.ads	2011-10-09 05:03:58.000000000 +0200
@@ -31,7 +31,9 @@
 
    procedure Register_Python_Scripting
      (Repo          : Scripts.Scripts_Repository;
-      Module        : String);
+      Module        : String;
+      Program_Name  : String := "python";
+      Python_Home   : String := "");
    procedure Unregister_Python_Scripting
      (Repo : Scripts.Scripts_Repository);
    --  Does nothing, since python was not compiled in.
