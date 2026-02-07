--- cad_source/other/AGraphLaz/Vectors/ExtSys.pas.orig	2017-05-01 09:49:55 UTC
+++ cad_source/other/AGraphLaz/Vectors/ExtSys.pas
@@ -10,7 +10,7 @@ interface
 
 uses
   {$IFDEF V_WIN32}{$ENDIF}
-  {$IFDEF LINUX}{$IFDEF V_DELPHI}Libc{$ELSE}Linux{,cmem}{$ENDIF},{$ENDIF}
+  {$IFDEF FREEBSD}{$IFDEF V_DELPHI}Libc{$ELSE}unixtype,sysctl{,cmem}{$ENDIF},{$ENDIF}
   SysUtils, {$IFDEF V_D4}SysConst, {$ENDIF}ExtType, VectErr{$IFNDEF LINUX}, Windows{$ENDIF};
 
 const
@@ -574,12 +574,13 @@ begin
   end;
   Result:=MemSize;
 {$ELSE}
-{$IFDEF LINUX}
+{$IFDEF FREEBSD}
 var
-  SI: TSysInfo;
+  page_count, pagesize : UInt32;
+  len : size_t = sizeof(UInt32);
 begin
-  if sysinfo(@SI){IFDEF V_DELPHI} = 0{ENDIF} then
-    Result:=SI.totalram
+  if (FPsysctlbyname('hw.pagesize', @pagesize, @len, nil, 0) {IFDEF V_DELPHI} = 0{ENDIF}) and (FPsysctlbyname('vm.stats.vm.v_page_count', @page_count, @len, nil, 0){IFDEF V_DELPHI} = 0{ENDIF}) then
+    Result:=page_count*pagesize
   else
     Result:=0;
 {$ELSE}
@@ -598,12 +599,13 @@ begin
   GlobalMemoryStatus({$IFDEF V_FREEPASCAL}@{$ENDIF}MemoryStatus);
   Result:=MemoryStatus.dwAvailPhys;
 {$ELSE}
-{$IFDEF LINUX}
+{$IFDEF FREEBSD}
 var
-  SI: TSysInfo;
+  free_count, pagesize : UInt32;
+  len : size_t = sizeof(UInt32);
 begin
-  if sysinfo(@SI){IFDEF V_DELPHI} = 0{ENDIF} then
-    Result:=SI.freeram
+  if (FPsysctlbyname('hw.pagesize', @pagesize, @len, nil, 0) {IFDEF V_DELPHI} = 0{ENDIF}) and (FPsysctlbyname('vm.stats.vm.v_free_count', @free_count, @len, nil, 0){IFDEF V_DELPHI} = 0{ENDIF}) then
+    Result:=free_count*pagesize
   else
     Result:=0;
 {$ELSE}
