--- gnatbind.adb.orig	Fri Sep  1 10:13:51 2000
+++ gnatbind.adb	Fri Feb  8 21:50:43 2002
@@ -183,7 +183,7 @@
 
    Next_Arg := 1;
    Scan_Args : loop
-      exit when Next_Arg >= Arg_Count;
+      exit Scan_Args when Next_Arg >= Arg_Count;
       declare
          Next_Argv : String (1 .. Len_Arg (Next_Arg));
 
