--- src/ghdldrv/ghdldrv.adb.orig	2015-10-23 05:51:44 UTC
+++ src/ghdldrv/ghdldrv.adb
@@ -42,8 +42,8 @@ package body Ghdldrv is
    --  Name of the tools used.
    Compiler_Cmd : String_Access := null;
    Post_Processor_Cmd : String_Access := null;
-   Assembler_Cmd : constant String := "as";
-   Linker_Cmd : constant String := "gcc";
+   Assembler_Cmd : aliased String := "@AS_COMMAND@";
+   Linker_Cmd : aliased String := "@LINKER_COMMAND@";
 
    --  Path of the tools.
    Compiler_Path : String_Access;
@@ -502,8 +502,9 @@ package body Ghdldrv is
       --  Linker.
       Linker_Path := Locate_Exec_On_Path (Linker_Cmd);
       if Linker_Path = null then
-         Tool_Not_Found (Linker_Cmd);
+         Assembler_Path := Assembler_Cmd'Access;
       end if;
+      Linker_Path := Linker_Cmd'Access;
    end Locate_Tools;
 
    procedure Setup_Compiler (Load : Boolean)
