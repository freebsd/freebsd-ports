--- compiler/systems/t_bsd.pas.orig	2015-11-13 21:15:29 UTC
+++ compiler/systems/t_bsd.pas
@@ -192,6 +192,8 @@ begin
       DynamicLinker:='/usr/libexec/ld.so'
      else if target_info.system in systems_netbsd then
       DynamicLinker:='/usr/libexec/ld.elf_so'
+     else if target_info.system=system_x86_64_dragonfly then
+      DynamicLinker:='/libexec/ld-elf.so.2'
      else
        DynamicLinker:='';
    end;
@@ -718,7 +720,10 @@ begin
   Replace(cmdstr,'$DYNLINK',DynLinkStr);
   if (target_info.system in systems_darwin) then
     Replace(cmdstr,'$PRTOBJ',GetDarwinPrtobjName(false));
-  BinStr:=FindUtil(utilsprefix+BinStr);
+  if target_info.system=system_x86_64_dragonfly then
+     BinStr:='/usr/libexec/binutils225/elf/ld.bfd'
+  else
+     BinStr:=FindUtil(utilsprefix+BinStr);
 
   { create dsym file? }
   extdbgbinstr:='';
