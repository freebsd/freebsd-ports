--- gnatls.adb.orig	Fri Sep  1 10:13:51 2000
+++ gnatls.adb	Fri Feb  8 22:04:50 2002
@@ -678,7 +678,7 @@
 
    Next_Arg := 1;
    Scan_Args : loop
-      exit when Next_Arg >= Arg_Count;
+      exit Scan_Args when Next_Arg >= Arg_Count;
       declare
          Next_Argv : String (1 .. Len_Arg (Next_Arg));
 
