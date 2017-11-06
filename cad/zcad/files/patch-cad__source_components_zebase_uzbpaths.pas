--- cad_source/components/zebase/uzbpaths.pas.orig	2017-05-01 09:50:10 UTC
+++ cad_source/components/zebase/uzbpaths.pas
@@ -19,7 +19,8 @@
 unit uzbpaths;
 {$INCLUDE def.inc}
 interface
-uses uzbtypes,Masks,LCLProc,uzbtypesbase,{$IFNDEF DELPHI}LazUTF8,{$ENDIF}sysutils;
+uses uzbtypes,Masks,LCLProc,uzbtypesbase,{$IFNDEF DELPHI}LazUTF8,{$ENDIF}
+{$IFDEF UNIX}baseunix,{$ENDIF}sysutils;
 type
   TFromDirIterator=procedure (filename:GDBString);
   TFromDirIteratorObj=procedure (filename:GDBString) of object;
@@ -35,7 +36,7 @@ function GetPartOfPath(out part:GDBStrin
 
 procedure FromDirIterator(const path,mask,firstloadfilename:GDBSTring;proc:TFromDirIterator;method:TFromDirIteratorObj);
 procedure FromDirsIterator(const path,mask,firstloadfilename:GDBString;proc:TFromDirIterator;method:TFromDirIteratorObj);
-var ProgramPath,SupportPath,TempPath:gdbstring;
+var ProgramPath,SupportPath,TempPath,UserPath:gdbstring;
 implementation
 //uses log;
 function FindInPaths(Paths,FileName:GDBString):GDBString;
@@ -147,11 +148,19 @@ begin
        DebugLn(sysutils.Format('[FILEOPS]FindInSupportPath: file not found:"%s"',[{$IFNDEF DELPHI}utf8tosys{$ENDIF}(FileName)]));
 end;
 function ExpandPath(path:GDBString):GDBString;
+{$IFDEF UNIX}var sb:stat;{$ENDIF}
 begin
      if path='' then
                     result:=programpath
 else if path[1]='*' then
-                    result:=programpath+copy(path,2,length(path)-1)
+begin
+{$IFDEF UNIX}
+    result:=UserPath+copy(path,2,length(path)-1);
+    if ((fpstat(result,sb) = 0) and fpS_ISDIR(sb.st_mode))
+         or not FileExists(result) then
+{$ENDIF}
+    result:=programpath+copy(path,2,length(path)-1);
+end
 else result:=path;
 result:=StringReplace(result,'/', PathDelim,[rfReplaceAll, rfIgnoreCase]);
 if DirectoryExists({$IFNDEF DELPHI}utf8tosys{$ENDIF}(result)) then
@@ -242,4 +251,10 @@ initialization
   if (TempPath[length(TempPath)]<>PathDelim)
    then
        TempPath:=TempPath+PathDelim;
+{$IFDEF UNIX}
+  UserPath:=GetUserDir+'.zcad/';
+  ForceDirectories(UserPath+'autosave');
+  ForceDirectories(UserPath+'components');
+  ForceDirectories(UserPath+'rtl');
+{$ENDIF}
 end.
