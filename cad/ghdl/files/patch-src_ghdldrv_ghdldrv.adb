--- src/ghdldrv/ghdldrv.adb.orig	2019-10-23 05:39:27 UTC
+++ src/ghdldrv/ghdldrv.adb
@@ -460,7 +460,7 @@ package body Ghdldrv is
          Assembler_Cmd := new String'("as");
       end if;
       if Linker_Cmd = null then
-         Linker_Cmd := new String'("gcc");
+         Linker_Cmd := new String'("cc");
       end if;
    end Set_Tools_Name;
 
