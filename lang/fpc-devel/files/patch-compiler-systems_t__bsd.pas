--- compiler/systems/t_bsd.pas	2023-10-27 23:25:22.849393000 -0500
+++ compiler/systems/t_bsd.pas	2023-10-27 23:26:39.226882000 -0500
@@ -115,6 +115,8 @@
   if not Dontlinkstdlibpath Then
    if target_info.system in systems_openbsd then
      LibrarySearchPath.AddLibraryPath(sysrootpath,'=/usr/lib;=$OPENBSD_X11BASE/lib;=$OPENBSD_LOCALBASE/lib',true)
+   else if target_info.system in systems_freebsd then
+     LibrarySearchPath.AddLibraryPath(sysrootpath,'=/usr/lib;=$FREEBSD_LOCALBASE/lib',true)
    else
      LibrarySearchPath.AddLibraryPath(sysrootpath,'=/lib;=/usr/lib;=/usr/X11R6/lib',true);
 end;
@@ -130,7 +132,9 @@
   if cs_link_lld in current_settings.globalswitches then
     LdProgram:='ld.lld'
   else if target_info.system in (systems_openbsd+systems_freebsd+[system_x86_64_dragonfly]) then
-    LdProgram:='ld.bfd';
+    LdProgram:=GetEnvPChar('FPC_LDPATH');
+    if not FileExists(LdProgram,True) then
+       LdProgram:='ld.bfd';
   LibrarySuffix:=' ';
   LdSupportsNoResponseFile := (target_info.system in ([system_m68k_netbsd]+systems_darwin));
   with Info do
