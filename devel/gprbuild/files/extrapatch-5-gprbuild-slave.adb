--- src/gprbuild-compilation-slave.adb.orig	2014-04-17 09:50:17 UTC
+++ src/gprbuild-compilation-slave.adb
@@ -817,7 +817,7 @@ package body Gprbuild.Compilation.Slave
                S : Slave := Slave_S.Element (C);
             begin
                Proc (S);
-               Pool (C) := S;
+               Pool.Replace_Element (Position => C, New_Item => S);
             end;
          end loop;
       end Iterate;
