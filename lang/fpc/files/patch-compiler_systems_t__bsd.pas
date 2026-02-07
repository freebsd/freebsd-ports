--- compiler/systems/t_bsd.pas.orig	2024-06-14 09:29:25.000000000 -0500
+++ compiler/systems/t_bsd.pas	2024-06-15 23:36:51.623753000 -0500
@@ -114,6 +114,8 @@
   if not Dontlinkstdlibpath Then
    if target_info.system in systems_openbsd then
      LibrarySearchPath.AddLibraryPath(sysrootpath,'=/usr/lib;=$OPENBSD_X11BASE/lib;=$OPENBSD_LOCALBASE/lib',true)
+   else if target_info.system in systems_freebsd then
+     LibrarySearchPath.AddLibraryPath(sysrootpath,'=/usr/lib;=$FREEBSD_LOCALBASE/lib',true)
    else
      LibrarySearchPath.AddLibraryPath(sysrootpath,'=/lib;=/usr/lib;=/usr/X11R6/lib',true);
 end;
@@ -148,6 +150,8 @@
       DynamicLinker:='/usr/libexec/ld.so'
      else if target_info.system in systems_netbsd then
       DynamicLinker:='/usr/libexec/ld.elf_so'
+     else if target_info.system in systems_freebsd then
+      DynamicLinker:='/usr/libexec/ld-elf.so.1'
      else if target_info.system=system_x86_64_dragonfly then
       DynamicLinker:='/libexec/ld-elf.so.2'
      else
