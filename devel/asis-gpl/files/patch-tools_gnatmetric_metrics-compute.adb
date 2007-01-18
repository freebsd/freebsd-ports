--- tools/gnatmetric/metrics-compute.adb.orig	Mon Jan  1 02:34:48 2007
+++ tools/gnatmetric/metrics-compute.adb	Mon Jan  1 02:38:25 2007
@@ -1429,7 +1429,7 @@
       if Debug_Output then
          Info ("gnatmetric: Creating the tree for " & Source_Name (SF));
 
-         Info_No_EOL ("gcc -c -gnatc -gnatt -gnatws");
+         Info_No_EOL ("gnatgcc -c -gnatc -gnatt -gnatws");
 
          for J in Arg_List'Range loop
             Info_No_EOL (" " &  Arg_List (J).all);
