--- cad_source/zcad/gui/uzcmainwindow.pas.orig	2017-05-01 09:49:49 UTC
+++ cad_source/zcad/gui/uzcmainwindow.pas
@@ -693,7 +693,7 @@ begin
 
           mem.init({$IFDEF DEBUGBUILD}'{71D987B4-8C57-4C62-8C12-CFC24A0A9C9A}',{$ENDIF}1024);
           SavedUnit^.SavePasToMem(mem);
-          mem.SaveToFile(expandpath(ProgramPath+'rtl'+PathDelim+'savedvar.pas'));
+          mem.SaveToFile(expandpath(UserPath+'rtl'+PathDelim+'savedvar.pas'));
           mem.done;
           end;
 
