--- src/ghdldrv/ghdldrv.adb.orig	2021-02-02 19:52:50 UTC
+++ src/ghdldrv/ghdldrv.adb
@@ -483,7 +483,7 @@ package body Ghdldrv is
          Cmd.Assembler_Cmd := new String'("as");
       end if;
       if Cmd.Linker_Cmd = null then
-         Cmd.Linker_Cmd := new String'("gcc");
+         Cmd.Linker_Cmd := new String'("cc");
       end if;
    end Set_Tools_Name;
 
@@ -755,8 +755,8 @@ package body Ghdldrv is
       Put_Line ("   Set the path of the ghdl1 compiler");
       Put_Line (" --AS=as");
       Put_Line ("   Use as for the assembler");
-      Put_Line (" --LINK=gcc");
-      Put_Line ("   Use gcc for the linker driver");
+      Put_Line (" --LINK=cc");
+      Put_Line ("   Use cc for the linker driver");
       Put_Line (" -S");
       Put_Line ("   Do not assemble");
       Put_Line (" -o FILE");
