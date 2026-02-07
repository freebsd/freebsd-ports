--- cad_source/zcad/commands/uzccominterface.pas.orig	2017-05-01 09:49:51 UTC
+++ cad_source/zcad/commands/uzccominterface.pas
@@ -477,7 +477,7 @@ var
 begin
   try
     // create a new xml config file
-    filename:=utf8tosys(ProgramPath+'components/defaultlayout.xml');
+    filename:=utf8tosys(UserPath+'components/defaultlayout.xml');
     SaveLayoutToFile(filename);
     exit;
     XMLConfig:=TXMLConfigStorage.Create(filename,false);
@@ -702,7 +702,7 @@ var
 begin
            mem.init({$IFDEF DEBUGBUILD}'{A1891083-67C6-4C21-8012-6D215935F6A6}',{$ENDIF}1024);
            SysVarUnit^.SavePasToMem(mem);
-           mem.SaveToFile(expandpath(ProgramPath+'rtl/sysvar.pas'));
+           mem.SaveToFile(expandpath(UserPath+'rtl/sysvar.pas'));
            mem.done;
            result:=cmd_ok;
 end;
