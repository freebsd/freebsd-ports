--- asis/a4g-gnat_int.adb.orig	2013-04-16 14:49:49.000000000 +0000
+++ asis/a4g-gnat_int.adb
@@ -231,44 +231,11 @@ package body A4G.GNAT_Int is
       end if;
 
       if Strong_Version_Check then
-         --  We check only the dates here!
-         First_A_Idx :=
-           Index (Source  => ASIS_GNAT_V,
-                  Pattern => "(") + 1;
-
-         First_T_Idx :=
-           Index (Source  => Tree_Version_String.all,
-                  Pattern => "(") + 1;
-
-         Last_A_Idx := Index (Source  => ASIS_GNAT_V,
-                     Pattern => ")") - 1;
-
-         if Index (Source  => ASIS_GNAT_V, Pattern => "-") /= 0 then
-            Last_A_Idx := Index (Source  => ASIS_GNAT_V,
-                                 Pattern => "-") - 1;
-         end if;
-
-         Last_T_Idx := Index (Source  => Tree_Version_String.all,
-                              Pattern => ")") - 1;
-
-         if Index (Source  => Tree_Version_String.all, Pattern => "-") /=
-            0
-         then
-            Last_T_Idx :=
-              Index (Source  => Tree_Version_String.all,
-                     Pattern => "-") - 1;
-         end if;
-
-         if ASIS_GNAT_V (First_A_Idx .. Last_A_Idx) /=
-            Tree_Version_String (First_T_Idx .. Last_T_Idx)
-         then
-            Close (Desc, File_Closed);
-            Ada.Exceptions.Raise_Exception
-              (Program_Error'Identity,
-               A_Name_Buffer (1 .. A_Name_Len) &
-               ": Inconsistent versions of GNAT [" & Tree_Version_String.all &
-               "] and ASIS [" & ASIS_GNAT_V & ']');
-         end if;
+         --  No need for any version check at all
+         --  FreeBSD Ports system ensures gnat_util is from same sources
+         --  as comiler building ASIS
+         
+         null;
 
       end if;
 
