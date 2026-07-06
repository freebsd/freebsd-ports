
  Patch GPRBuild to search host's ${PREFIX} in addition to the installed
  GNAT ${PREFIX}. This enables easier integration of Ada Ports, and removes
  the restriction of of limited "with"-ing of GPR projects to the GNAT
  ${PREFIX} only.

--- gpr/src/gpr-env.adb.orig	2026-06-22 14:14:27 UTC
+++ gpr/src/gpr-env.adb
@@ -2053,6 +2053,10 @@ package body GPR.Env is
 
             Self.Path.Append
               (Runtime_Dir & "share" & Directory_Separator & "gpr");
+
+            Self.Path.Append
+              (%%PREFIX%% & Directory_Separator &
+                "share" & Directory_Separator & "gpr");
          end;
       end if;
    end Initialize_Default_Project_Path;
