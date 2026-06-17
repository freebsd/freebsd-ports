--- compiler/systems/t_bsd.pas	2026-04-28 15:15:11.000000000 -0700
+++ compiler/systems/t_bsd.pas	2026-04-30 15:44:01.774194000 -0700
@@ -118,6 +118,8 @@
      LibrarySearchPath.AddLibraryPath(sysrootpath,'=/usr/lib;=$OPENBSD_X11BASE/lib;=$OPENBSD_LOCALBASE/lib',true)
    else if target_info.system in systems_dragonfly then
      LibrarySearchPath.AddLibraryPath(sysrootpath,'=/lib;=/usr/lib;=/usr/local/lib',true)
+   else if target_info.system in systems_freebsd then
+     LibrarySearchPath.AddLibraryPath(sysrootpath,'=/usr/lib;=$FREEBSD_LOCALBASE/lib',true)
    else
      LibrarySearchPath.AddLibraryPath(sysrootpath,'=/lib;=/usr/lib;=/usr/X11R6/lib',true);
 end;
@@ -135,7 +137,11 @@
   if (cs_link_lld in current_settings.globalswitches) or (target_info.system = system_x86_64_openbsd) then
     LdProgram:='ld.lld'
   else if target_info.system in (systems_openbsd+systems_freebsd+[system_x86_64_dragonfly]) then
-    LdProgram:='ld.bfd';
+   begin
+    LdProgram:=GetEnvPChar('FPC_LDPATH');
+    if not FileExists(LdProgram,True) then
+       LdProgram:='ld.bfd';
+   end;
   LibrarySuffix:=' ';
   LdSupportsNoResponseFile := (target_info.system in ([system_m68k_netbsd]+systems_darwin));
   with Info do
