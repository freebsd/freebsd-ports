--- make.adb.orig	Fri Sep  1 10:13:54 2000
+++ make.adb	Fri Feb  8 21:44:31 2002
@@ -1824,7 +1824,7 @@
 
       Next_Arg := 1;
       Scan_Args : loop
-         exit when Next_Arg > Argument_Count;
+         exit Scan_Args when Next_Arg > Argument_Count;
          Scan_Make_Arg (Argument (Next_Arg));
          Next_Arg := Next_Arg + 1;
       end loop Scan_Args;
