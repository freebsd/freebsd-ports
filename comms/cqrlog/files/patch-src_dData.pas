--- src/dData.pas.orig	2018-07-11 03:36:41 UTC
+++ src/dData.pas
@@ -904,22 +904,22 @@ begin
   if not DirectoryExistsUTF8(fHomeDir+'members') then
     CreateDirUTF8(fHomeDir+'members');
   fMembersDir := fHomeDir+'members'+PathDelim;
-  fGlobalMembersDir := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+
+  fGlobalMembersDir := ExpandFileNameUTF8('%%DATADIR%%'+PathDelim+'share'+PathDelim+'cqrlog'+
                        PathDelim+'members'+PathDelim);
 
   if DirectoryExistsUTF8(fHomeDir+'zipcodes') then
     fZipCodeDir := fHomeDir+'zipcodes'+PathDelim
   else
-    fZipCodeDir := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog')+
+    fZipCodeDir := ExpandFileNameUTF8('%%DATADIR%%'+PathDelim+'share'+PathDelim+'cqrlog')+
                    PathDelim+'zipcodes'+PathDelim;
 
   if not DirectoryExistsUTF8(fHomeDir+'images') then
     CreateDirUTF8(fHomeDir+'images');
 
-  fHelpDir := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+
+  fHelpDir := ExpandFileNameUTF8('%%DATADIR%%'+PathDelim+'share'+PathDelim+'cqrlog'+
               PathDelim+'help'+PathDelim);
 
-  fShareDir := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+
+  fShareDir := ExpandFileNameUTF8('%%DATADIR%%'+PathDelim+'share'+PathDelim+'cqrlog'+
                PathDelim);
 
   if not DirectoryExistsUTF8(fHomeDir + 'lotw') then
@@ -942,7 +942,7 @@ procedure TdmData.PrepareCtyData;
 var
   s,d : String;
 begin
-  s := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+PathDelim+'ctyfiles'+PathDelim);
+  s := ExpandFileNameUTF8('%%DATADIR%%'+PathDelim+'share'+PathDelim+'cqrlog'+PathDelim+'ctyfiles'+PathDelim);
   d := fHomeDir+'ctyfiles'+PathDelim;
 
   if not FileExistsUTF8(fHomeDir+'ctyfiles'+PathDelim+'AreaOK1RR.tbl') then
@@ -1015,7 +1015,7 @@ procedure TdmData.PrepareXplanetDir;
 var
   s,d : String;
 begin
-  s := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+PathDelim+'xplanet'+PathDelim);
+  s := ExpandFileNameUTF8('%%DATADIR%%'+PathDelim+'share'+PathDelim+'cqrlog'+PathDelim+'xplanet'+PathDelim);
   d := fHomeDir+'xplanet'+PathDelim;
   if not FileExistsUTF8(d+'geoconfig') then
     CopyFile(s+'geoconfig',d+'geoconfig')
@@ -1025,7 +1025,7 @@ procedure TdmData.PrepareVoice_keyerDir;
 var
   s,d : String;
 begin
-  s := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+PathDelim+'voice_keyer'+PathDelim);
+  s := ExpandFileNameUTF8('%%DATADIR%%'+PathDelim+'share'+PathDelim+'cqrlog'+PathDelim+'voice_keyer'+PathDelim);
   d := fHomeDir+'voice_keyer'+PathDelim;
   if not FileExistsUTF8(d+'voice_keyer.sh') then
     CopyFile(s+'voice_keyer.sh',d+'voice_keyer.sh')
@@ -3367,12 +3367,12 @@ var
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
@@ -4209,17 +4209,7 @@ begin
   Result := '';
   Paths := TStringList.Create;
   try
-    Paths.Add('/usr/lib64/');
-    Paths.Add('/lib64/');
-    Paths.Add('/usr/lib/x86_64-linux-gnu/');
-    Paths.Add('/usr/lib64/mysql/');
-    Paths.Add('/lib/x86_64-linux-gnu/');
-
-    Paths.Add('/usr/lib/i386-linux-gnu/');
-    Paths.Add('/lib/i386-linux-gnu/');
-    Paths.Add('/usr/lib/');
-    Paths.Add('/lib/');
-    Paths.Add('/usr/lib/mysql/');
+    Paths.Add('%%LOCALBASE%%/lib/');
 
     Result := MyFindFile('libmariadbclient.so*', Paths);
     if (Result='') then
