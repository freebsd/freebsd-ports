--- src/ghdldrv/ghdldrv.adb.orig	2015-05-30 07:12:42 UTC
+++ src/ghdldrv/ghdldrv.adb
@@ -43,8 +43,8 @@ package body Ghdldrv is
    --  Name of the tools used.
    Compiler_Cmd : String_Access := null;
    Post_Processor_Cmd : String_Access := null;
-   Assembler_Cmd : constant String := "as";
-   Linker_Cmd : constant String := "gcc";
+   Assembler_Cmd : aliased String := "@AS_COMMAND@";
+   Linker_Cmd : aliased String := "@LINKER_COMMAND@";
 
    --  Path of the tools.
    Compiler_Path : String_Access;
@@ -467,15 +467,9 @@ package body Ghdldrv is
          end if;
       end if;
       if Compile_Kind >= Compile_Gcc then
-         Assembler_Path := Locate_Exec_On_Path (Assembler_Cmd);
-         if Assembler_Path = null and not Flag_Asm then
-            Tool_Not_Found (Assembler_Cmd);
-         end if;
-      end if;
-      Linker_Path := Locate_Exec_On_Path (Linker_Cmd);
-      if Linker_Path = null then
-         Tool_Not_Found (Linker_Cmd);
+         Assembler_Path := Assembler_Cmd'Access;
       end if;
+      Linker_Path := Linker_Cmd'Access;
    end Locate_Tools;
 
    procedure Setup_Compiler (Load : Boolean)
