--- unit8.pas.orig	2016-01-27 13:11:27.063394000 -0500
+++ unit8.pas	2016-01-27 13:14:04.758776000 -0500
@@ -170,7 +170,7 @@
 procedure new_pm;
 var
   i,rc:integer;
-  s:utf8string;
+  s:AnsiString;
 begin
 if InputQuery(txt_edit+' '+FormPM.mpw.Caption, '', s) then
    begin
@@ -190,7 +190,7 @@
 end;
 
 procedure editpw_pm;
-var s:utf8string;
+var s:AnsiString;
 begin
 if FormPM.StringGridPM.Row=0 then
    begin
@@ -207,7 +207,7 @@
 end;
 
 procedure setdescription_pm;
-var s:utf8string;
+var s:AnsiString;
 begin
 if FormPM.StringGridPM.Row=0 then
    begin
