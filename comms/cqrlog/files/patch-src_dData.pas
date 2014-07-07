--- src/dData.pas.orig	2014-04-13 05:14:38.000000000 -0700
+++ src/dData.pas	2014-07-01 00:20:19.000000000 -0700
@@ -850,22 +850,22 @@
   if DirectoryExistsUTF8(fHomeDir+'members') then
     fMembersDir := fHomeDir+'members'+PathDelim
   else
-    fMembersDir := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+
+    fMembersDir := ExpandFileNameUTF8('%%PREFIX%%'+PathDelim+'share'+PathDelim+'cqrlog'+
                    PathDelim+'members'+PathDelim);
 
   if DirectoryExistsUTF8(fHomeDir+'zipcodes') then
     fZipCodeDir := fHomeDir+'zipcodes'+PathDelim
   else
-    fZipCodeDir := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog')+
+    fZipCodeDir := ExpandFileNameUTF8('%%PREFIX%%'+PathDelim+'share'+PathDelim+'cqrlog')+
                    PathDelim+'zipcodes'+PathDelim;
 
   if not DirectoryExistsUTF8(fHomeDir+'images') then
     CreateDirUTF8(fHomeDir+'images');
 
-  fHelpDir := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+
+  fHelpDir := ExpandFileNameUTF8('%%PREFIX%%'+PathDelim+'share'+PathDelim+'cqrlog'+
               PathDelim+'help'+PathDelim);
 
-  fShareDir := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+
+  fShareDir := ExpandFileNameUTF8('%%PREFIX%%'+PathDelim+'share'+PathDelim+'cqrlog'+
                PathDelim);
 
   if not DirectoryExistsUTF8(fHomeDir + 'lotw') then
@@ -888,7 +888,7 @@
 var
   s,d : String;
 begin
-  s := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+PathDelim+'ctyfiles'+PathDelim);
+  s := ExpandFileNameUTF8('%%PREFIX%%'+PathDelim+'share'+PathDelim+'cqrlog'+PathDelim+'ctyfiles'+PathDelim);
   d := fHomeDir+'ctyfiles'+PathDelim;
 
   if not FileExistsUTF8(fHomeDir+'ctyfiles'+PathDelim+'AreaOK1RR.tbl') then
@@ -952,7 +952,7 @@
 var
   s,d : String;
 begin
-  s := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+PathDelim+'xplanet'+PathDelim);
+  s := ExpandFileNameUTF8('%%LOCALBASE%%'+PathDelim+'share'+PathDelim+'cqrlog'+PathDelim+'xplanet'+PathDelim);
   d := fHomeDir+'xplanet'+PathDelim;
   if not FileExistsUTF8(d+'geoconfig') then
     CopyFile(s+'geoconfig',d+'geoconfig')
@@ -962,7 +962,7 @@
 var
   s,d : String;
 begin
-  s := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+PathDelim+'voice_keyer'+PathDelim);
+  s := ExpandFileNameUTF8('%%PREFIX%%'+PathDelim+'share'+PathDelim+'cqrlog'+PathDelim+'voice_keyer'+PathDelim);
   d := fHomeDir+'voice_keyer'+PathDelim;
   if not FileExistsUTF8(d+'voice_keyer.sh') then
     CopyFile(s+'voice_keyer.sh',d+'voice_keyer.sh')
@@ -1061,7 +1061,7 @@
   if lib <> '' then
     fDLLUtilName := lib;
 
-  lib := FindLib('/usr/lib64/','libmysqlclient.so*');
+  lib := FindLib('%%LOCALBASE%%/lib/','libmysqlclient.so*');
   if (lib = '') then
     lib := FindLib('/lib64/','libmysqlclient.so*');
   if (lib='') then
