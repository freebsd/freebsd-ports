--- compiler/systems/t_bsd.pas	2014-12-07 15:27:02.000000000 -0500
+++ compiler/systems/t_bsd.pas	2019-12-30 19:00:54.968908000 -0500
@@ -60,6 +60,7 @@
     private
       LdSupportsNoResponseFile : boolean;
       LibrarySuffix : Char;
+      LdPath : String;
       Function  WriteResponseFile(isdll:boolean) : Boolean;
       function GetDarwinCrt1ObjName(isdll: boolean): TCmdStr;
       Function GetDarwinPrtobjName(isdll: boolean): TCmdStr;
@@ -139,6 +140,9 @@
 }
 begin
   LibrarySuffix:=' ';
+  LdPath:=GetEnvironmentVariable('FPC_LDPATH');
+  if not FileExists(LdPath,True) then
+    LdPath:='%%FPC_LDPATH%%';
   LdSupportsNoResponseFile := (target_info.system in ([system_m68k_netbsd]+systems_darwin));
   with Info do
    begin
@@ -146,8 +150,8 @@
        begin
          if not(target_info.system in systems_darwin) then
            begin
-             ExeCmd[1]:='ld $TARGET $EMUL $OPT $DYNLINK $STATIC $GCSECTIONS $STRIP -L. -o $EXE $CATRES';
-             DllCmd[1]:='ld $TARGET $EMUL $OPT -shared -L. -o $EXE $CATRES'
+             ExeCmd[1]:=LdPath + ' $TARGET $EMUL $OPT $DYNLINK $STATIC $GCSECTIONS $STRIP -L. -o $EXE $CATRES';
+             DllCmd[1]:=LdPath + ' $TARGET $EMUL $OPT -shared -L. -o $EXE $CATRES'
            end
          else
            begin
@@ -166,22 +170,22 @@
                programs with problems that require Valgrind will have more
                than 60KB of data (first 4KB of address space is always invalid)
              }
-               ExeCmd[1]:='ld $PRTOBJ $TARGET $EMUL $OPT $DYNLINK $STATIC $GCSECTIONS $STRIP -multiply_defined suppress -L. -o $EXE $CATRES';
+               ExeCmd[1]:=LdPath + ' $PRTOBJ $TARGET $EMUL $OPT $DYNLINK $STATIC $GCSECTIONS $STRIP -multiply_defined suppress -L. -o $EXE $CATRES';
              if not(cs_gdb_valgrind in current_settings.globalswitches) then
                ExeCmd[1]:=ExeCmd[1]+' -pagezero_size 0x10000';
 {$else ndef cpu64bitaddr}
-             ExeCmd[1]:='ld $PRTOBJ $TARGET $EMUL $OPT $DYNLINK $STATIC $GCSECTIONS $STRIP -multiply_defined suppress -L. -o $EXE $CATRES';
+             ExeCmd[1]:=LdPath + ' $PRTOBJ $TARGET $EMUL $OPT $DYNLINK $STATIC $GCSECTIONS $STRIP -multiply_defined suppress -L. -o $EXE $CATRES';
 {$endif ndef cpu64bitaddr}
              if (apptype<>app_bundle) then
-               DllCmd[1]:='ld $PRTOBJ $TARGET $EMUL $OPT $GCSECTIONS -dynamic -dylib -multiply_defined suppress -L. -o $EXE $CATRES'
+               DllCmd[1]:=LdPath + ' $PRTOBJ $TARGET $EMUL $OPT $GCSECTIONS -dynamic -dylib -multiply_defined suppress -L. -o $EXE $CATRES'
              else
-               DllCmd[1]:='ld $PRTOBJ $TARGET $EMUL $OPT $GCSECTIONS -dynamic -bundle -multiply_defined suppress -L. -o $EXE $CATRES'
+               DllCmd[1]:=LdPath + ' $PRTOBJ $TARGET $EMUL $OPT $GCSECTIONS -dynamic -bundle -multiply_defined suppress -L. -o $EXE $CATRES'
            end
        end
      else
        begin
-         ExeCmd[1]:='ld $TARGET $EMUL $OPT $DYNLINK $STATIC  $GCSECTIONS $STRIP -L. -o $EXE $RES';
-         DllCmd[1]:='ld $TARGET $EMUL $OPT $INIT $FINI $SONAME -shared -L. -o $EXE $RES';
+         ExeCmd[1]:=LdPath + ' $TARGET $EMUL $OPT $DYNLINK $STATIC  $GCSECTIONS $STRIP -L. -o $EXE $RES';
+         DllCmd[1]:=LdPath + ' $TARGET $EMUL $OPT $INIT $FINI $SONAME -shared -L. -o $EXE $RES';
        end;
      if not(target_info.system in systems_darwin) then
        DllCmd[2]:='strip --strip-unneeded $EXE'
@@ -192,6 +196,8 @@
       DynamicLinker:='/usr/libexec/ld.so'
      else if target_info.system in systems_netbsd then
       DynamicLinker:='/usr/libexec/ld.elf_so'
+     else if target_info.system=system_x86_64_dragonfly then
+      DynamicLinker:='/libexec/ld-elf.so.2'
      else
        DynamicLinker:='';
    end;
@@ -555,7 +561,7 @@
      While not SharedLibFiles.Empty do
       begin
         S:=SharedLibFiles.GetFirst;
-        if (s<>'c') or reorder then
+        if (((((((((s<>'c') and (s<>'iconv')) and (s<>'iconv')) and (s<>'iconv')) and (s<>'iconv')) and (s<>'iconv')) and (s<>'iconv')) and (s<>'iconv')) and (s<>'iconv')) or reorder then
          begin
            i:=Pos(target_info.sharedlibext,S);
            if i>0 then
@@ -718,7 +724,12 @@
   Replace(cmdstr,'$DYNLINK',DynLinkStr);
   if (target_info.system in systems_darwin) then
     Replace(cmdstr,'$PRTOBJ',GetDarwinPrtobjName(false));
-  BinStr:=FindUtil(utilsprefix+BinStr);
+  if target_info.system=system_x86_64_dragonfly then
+     BinStr:='/usr/libexec/binutils225/elf/ld.bfd';
+  if target_info.system in systems_freebsd then
+     BinStr:=LdPath
+  else
+     BinStr:=FindUtil(utilsprefix+BinStr);
 
   { create dsym file? }
   extdbgbinstr:='';
