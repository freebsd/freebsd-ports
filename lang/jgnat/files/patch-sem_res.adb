--- sem_res.adb.orig	Fri Sep  1 10:14:00 2000
+++ sem_res.adb	Fri Feb  8 21:31:04 2002
@@ -1460,7 +1460,7 @@
             if Present (It.Typ) then
                Get_Next_Interp (I, It);
             else
-               exit;
+               exit Interp_Loop;
             end if;
          end loop Interp_Loop;
       end if;
