--- compiler/systems/t_bsd.pas	2014-12-07 15:27:02.000000000 -0500
+++ compiler/systems/t_bsd.pas	2019-08-15 01:12:52.940972000 -0500
@@ -192,6 +192,8 @@
       DynamicLinker:='/usr/libexec/ld.so'
      else if target_info.system in systems_netbsd then
       DynamicLinker:='/usr/libexec/ld.elf_so'
+     else if target_info.system=system_x86_64_dragonfly then
+      DynamicLinker:='/libexec/ld-elf.so.2'
      else
        DynamicLinker:='';
    end;
@@ -555,7 +557,7 @@
      While not SharedLibFiles.Empty do
       begin
         S:=SharedLibFiles.GetFirst;
-        if (s<>'c') or reorder then
+        if ((((((s<>'c') and (s<>'iconv')) and (s<>'iconv')) and (s<>'iconv')) and (s<>'iconv')) and (s<>'iconv')) or reorder then
          begin
            i:=Pos(target_info.sharedlibext,S);
            if i>0 then
@@ -718,7 +720,12 @@
   Replace(cmdstr,'$DYNLINK',DynLinkStr);
   if (target_info.system in systems_darwin) then
     Replace(cmdstr,'$PRTOBJ',GetDarwinPrtobjName(false));
-  BinStr:=FindUtil(utilsprefix+BinStr);
+  if target_info.system=system_x86_64_dragonfly then
+     BinStr:='/usr/libexec/binutils225/elf/ld.bfd';
+  if target_info.system in systems_freebsd then
+     BinStr:='%%LDPATH%%'
+  else
+     BinStr:=FindUtil(utilsprefix+BinStr);
 
   { create dsym file? }
   extdbgbinstr:='';
