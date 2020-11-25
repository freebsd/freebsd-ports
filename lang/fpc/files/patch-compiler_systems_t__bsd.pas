--- compiler/systems/t_bsd.pas	2020-10-03 17:54:31.715884000 -0500
+++ compiler/systems/t_bsd.pas	2020-10-03 18:18:40.577288000 -0500
@@ -155,6 +155,8 @@
      LibrarySearchPath.AddLibraryPath(sysrootpath,'=/usr/lib',true)
    else if target_info.system in systems_openbsd then
      LibrarySearchPath.AddLibraryPath(sysrootpath,'=/usr/lib;=$OPENBSD_X11BASE/lib;=$OPENBSD_LOCALBASE/lib',true)
+   else if target_info.system in systems_freebsd then
+     LibrarySearchPath.AddLibraryPath(sysrootpath,'=/usr/lib;=$FREEBSD_LOCALBASE/lib',true)
    else
      LibrarySearchPath.AddLibraryPath(sysrootpath,'=/lib;=/usr/lib;=/usr/X11R6/lib',true);
 end;
@@ -167,6 +169,12 @@
 var
   LdProgram: string='ld';
 begin
+  if target_info.system in systems_freebsd then
+  begin
+    LdProgram:=GetEnvPChar('FPC_LDPATH');
+    if not FileExists(LdProgram,True) then
+      LdProgram:=GetEnvPChar('LOCALBASE')+'/bin/ld.bfd';
+  end;
   if target_info.system in (systems_openbsd+[system_x86_64_dragonfly]) then
     LdProgram:='ld.bfd';
   LibrarySuffix:=' ';
