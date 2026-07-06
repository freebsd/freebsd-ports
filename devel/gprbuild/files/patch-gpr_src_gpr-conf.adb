
  Patch GPRBuild to search host's ${PREFIX} in addition to the installed
  GNAT ${PREFIX}. This enables easier integration of Ada Ports, and removes
  the restriction of of limited "with"-ing of GPR projects to the GNAT
  ${PREFIX} only.

--- gpr/src/gpr-conf.adb.orig	2026-06-22 14:17:24 UTC
+++ gpr/src/gpr-conf.adb
@@ -2347,6 +2347,12 @@ package body GPR.Conf is
               Directory_Separator &
               "gnat");
          Compiler_Root := Compiler_Root.Next;
+         Add_Directory
+           (%%PREFIX%% &
+                Directory_Separator &
+                "share" &
+                Directory_Separator &
+                "gpr");
       end loop;
 
       --  Need to reset compilers for possible future reloads.
