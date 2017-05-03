--- cad_source/zcad/uzclog.pas.orig	2017-05-01 09:49:46 UTC
+++ cad_source/zcad/uzclog.pas
@@ -21,10 +21,11 @@ unit uzclog;
 {$mode objfpc}{$H+}
 interface
 uses UGDBOpenArrayOfByte,gzctnrvectordata,gzctnrstl,LazLoggerBase,
+     {$IFDEF UNIX}uzbpaths,{$ENDIF}
      LazLogger,strutils,sysutils{$IFNDEF DELPHI},LazUTF8{$ENDIF};
 const {$IFDEF DELPHI}filelog='log/zcad_delphi.log';{$ENDIF}
       {$IFDEF FPC}
-                  {$IFDEF LINUX}filelog='log/zcad_linux.log';{$ENDIF}
+                  {$IFDEF UNIX}filelog='zcad_unix.log';{$ENDIF}
                   {$IFDEF WINDOWS}filelog='log/zcad_windows.log';{$ENDIF}
       {$ENDIF}
       lp_IncPos=1;
@@ -131,7 +132,9 @@ var
 begin
      if assigned(SplashTextOut) then
                                    SplashTextOut(s,true);
-     logname:={$IFNDEF DELPHI}SysToUTF8{$ENDIF}(ExtractFilePath(paramstr(0)))+filelog+'hard';
+     logname:={$IFNDEF DELPHI}SysToUTF8{$ENDIF}
+             ({$IFDEF UNIX}UserPath{$ELSE}ExtractFilePath(paramstr(0)){$ENDIF})
+              +filelog+'hard';
      FileHandle:=0;
      if not fileexists({$IFNDEF DELPHI}UTF8ToSys{$ENDIF}(logname)) then
                                    FileHandle:=FileCreate({$IFNDEF DELPHI}UTF8ToSys{$ENDIF}(logname))
@@ -496,7 +499,9 @@ begin
 end;
 initialization
 begin
-    programlog.init({$IFNDEF DELPHI}SysToUTF8{$ENDIF}(ExtractFilePath(paramstr(0)))+filelog,LM_Error);
+   programlog.init({$IFNDEF DELPHI}SysToUTF8{$ENDIF}
+   ({$IFDEF UNIX}UserPath{$ELSE}ExtractFilePath(paramstr(0)){$ENDIF})
+   +filelog,LM_Error);
 end;
 finalization
     programlog.done;
