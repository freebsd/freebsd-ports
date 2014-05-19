FSF GNAT 4.9 doesn't have the mode setting capability in Set_Executable
procedure.  At least GPRBuild 2012 didn't use it.

--- src/gprinstall-install.adb.orig	2014-04-17 09:50:17.000000000 +0000
+++ src/gprinstall-install.adb
@@ -723,7 +723,7 @@ package body Gprinstall.Install is
 
                if Executable then
                   Set_Executable
-                    (Dest_Filename, Mode => S_Owner + S_Group + S_Others);
+                    (Dest_Filename);
                end if;
 
                --  Add file to manifest
