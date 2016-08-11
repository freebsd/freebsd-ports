--- asis/a4g-gnat_int.adb.orig	2016-05-16 09:17:27 UTC
+++ asis/a4g-gnat_int.adb
@@ -231,46 +231,10 @@ package body A4G.GNAT_Int is
       Opt.Tree_Read;
 
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
-         if Index
-              (Source  => ASIS_GNAT_V (First_A_Idx .. Last_A_Idx),
-               Pattern => "-") /= 0
-         then
-            Last_A_Idx :=
-              Index (Source  => ASIS_GNAT_V (First_A_Idx .. Last_A_Idx),
-                     Pattern => "-") - 1;
-         end if;
-
-         Last_T_Idx := Index (Source  => Tree_Version_String.all,
-                              Pattern => ")") - 1;
-
-         if Index
-              (Source  => Tree_Version_String.all (First_T_Idx .. Last_T_Idx),
-               Pattern => "-") /= 0
-         then
-            Last_T_Idx :=
-              Index (Source  =>
-                       Tree_Version_String.all (First_T_Idx .. Last_T_Idx),
-                     Pattern => "-") - 1;
-         end if;
-
-         if ASIS_GNAT_V (First_A_Idx .. Last_A_Idx) /=
-            Tree_Version_String (First_T_Idx .. Last_T_Idx)
-         then
-            Note_Version_Mismatch;
-         end if;
-
+         --  No need for any version check at all
+         --  FreeBSD Ports system ensures gnat_util is from same sources
+         --  as compiler building ASIS
+         null;
       end if;
 
       --  GNAT/ASIS version check
