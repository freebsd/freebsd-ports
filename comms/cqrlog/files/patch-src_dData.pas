--- src/dData.pas.orig	2016-05-07 08:21:24 UTC
+++ src/dData.pas
@@ -910,22 +910,22 @@ begin
   if DirectoryExistsUTF8(fHomeDir+'members') then
     fMembersDir := fHomeDir+'members'+PathDelim
   else
-    fMembersDir := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+
+    fMembersDir := ExpandFileNameUTF8('%%DATADIR%%'+
                    PathDelim+'members'+PathDelim);
 
   if DirectoryExistsUTF8(fHomeDir+'zipcodes') then
     fZipCodeDir := fHomeDir+'zipcodes'+PathDelim
   else
-    fZipCodeDir := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog')+
+    fZipCodeDir := ExpandFileNameUTF8('%%DATADIR%%')+
                    PathDelim+'zipcodes'+PathDelim;
 
   if not DirectoryExistsUTF8(fHomeDir+'images') then
     CreateDirUTF8(fHomeDir+'images');
 
-  fHelpDir := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+
+  fHelpDir := ExpandFileNameUTF8('%%DATADIR%%'+
               PathDelim+'help'+PathDelim);
 
-  fShareDir := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+
+  fShareDir := ExpandFileNameUTF8('%%DATADIR%%'+
                PathDelim);
 
   if not DirectoryExistsUTF8(fHomeDir + 'lotw') then
@@ -948,7 +948,7 @@ procedure TdmData.PrepareCtyData;
 var
   s,d : String;
 begin
-  s := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+PathDelim+'ctyfiles'+PathDelim);
+  s := ExpandFileNameUTF8('%%DATADIR%%'+PathDelim+'ctyfiles'+PathDelim);
   d := fHomeDir+'ctyfiles'+PathDelim;
 
   if not FileExistsUTF8(fHomeDir+'ctyfiles'+PathDelim+'AreaOK1RR.tbl') then
@@ -1016,7 +1016,7 @@ procedure TdmData.PrepareXplanetDir;
 var
   s,d : String;
 begin
-  s := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+PathDelim+'xplanet'+PathDelim);
+  s := ExpandFileNameUTF8('%%DATADIR%%'+PathDelim+'xplanet'+PathDelim);
   d := fHomeDir+'xplanet'+PathDelim;
   if not FileExistsUTF8(d+'geoconfig') then
     CopyFile(s+'geoconfig',d+'geoconfig')
@@ -1026,7 +1026,7 @@ procedure TdmData.PrepareVoice_keyerDir;
 var
   s,d : String;
 begin
-  s := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+PathDelim+'voice_keyer'+PathDelim);
+  s := ExpandFileNameUTF8('%%DATADIR%%'+PathDelim+'voice_keyer'+PathDelim);
   d := fHomeDir+'voice_keyer'+PathDelim;
   if not FileExistsUTF8(d+'voice_keyer.sh') then
     CopyFile(s+'voice_keyer.sh',d+'voice_keyer.sh')
@@ -1288,12 +1288,12 @@ begin
 
   {
 
-  if FileExistsUTF8('/usr/bin/mysqld') then
-    mysqld := '/usr/bin/mysqld';
-  if FileExistsUTF8('/usr/bin/mysqld_safe') then //Fedora
-    mysqld := '/usr/bin/mysqld_safe';
-  if FileExistsUTF8('/usr/sbin/mysqld') then //openSUSE
-    mysqld := '/usr/sbin/mysqld';
+  if FileExistsUTF8('%%LOCALBASE%%/bin/mysqld') then
+    mysqld := '%%LOCALBASE%%/bin/mysqld';
+  if FileExistsUTF8('%%LOCALBASE%%/bin/mysqld_safe') then //Fedora
+    mysqld := '%%LOCALBASE%%/bin/mysqld_safe';
+  if FileExistsUTF8('%%LOCALBASE%%/sbin/mysqld') then //openSUSE
+    mysqld := '%%LOCALBASE%%/sbin/mysqld';
   if mysqld = '' then  //don't know where mysqld is, so hopefully will be in  $PATH
     mysqld := 'mysqld';
 
@@ -3462,12 +3462,12 @@ var
   l : TStringList;
   info : String;
 begin
-  if FileExistsUTF8('/usr/bin/mysqld') then
-    Result := '/usr/bin/mysqld';
-  if FileExistsUTF8('/usr/bin/mysqld_safe') then //Fedora
-    Result := '/usr/bin/mysqld_safe';
-  if FileExistsUTF8('/usr/sbin/mysqld') then //openSUSE
-    Result := '/usr/sbin/mysqld';
+  if FileExistsUTF8('%%LOCALBASE%%/bin/mysqld') then
+    Result := '%%LOCALBASE%%/bin/mysqld';
+  if FileExistsUTF8('%%LOCALBASE%%/bin/mysqld_safe') then //Fedora
+    Result := '%%LOCALBASE%%/bin/mysqld_safe';
+  if FileExistsUTF8('%%LOCALBASE%%/sbin/mysqld') then //openSUSE
+    Result := '%%LOCALBASE%%/sbin/mysqld';
   if Result = '' then  //don't know where mysqld is, so hopefully will be in  $PATH
     Result := 'mysqld'
 end;
