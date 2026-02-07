--- src/dData.pas.orig	2021-01-16 14:03:35 UTC
+++ src/dData.pas
@@ -908,22 +908,22 @@ begin
   if not DirectoryExistsUTF8(fHomeDir+'members') then
     CreateDirUTF8(fHomeDir+'members');
   fMembersDir := fHomeDir+'members'+PathDelim;
-  fGlobalMembersDir := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+
+  fGlobalMembersDir := ExpandFileNameUTF8('%%DATADIR%%'+
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
@@ -1021,7 +1021,7 @@ procedure TdmData.PrepareXplanetDir;
 var
   s,d : String;
 begin
-  s := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+PathDelim+'xplanet'+PathDelim);
+  s := ExpandFileNameUTF8('%%DATADIR%%'+PathDelim+'xplanet'+PathDelim);
   d := fHomeDir+'xplanet'+PathDelim;
   if not FileExistsUTF8(d+'geoconfig') then
     CopyFile(s+'geoconfig',d+'geoconfig')
@@ -1031,7 +1031,7 @@ procedure TdmData.PrepareVoice_keyerDir;
 var
   s,d : String;
 begin
-  s := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+PathDelim+'voice_keyer'+PathDelim);
+  s := ExpandFileNameUTF8('%%DATADIR%%'+PathDelim+'voice_keyer'+PathDelim);
   d := fHomeDir+'voice_keyer'+PathDelim;
   if not FileExistsUTF8(d+'voice_keyer.sh') then
     CopyFile(s+'voice_keyer.sh',d+'voice_keyer.sh')
@@ -1098,15 +1098,15 @@ begin
   AProcess := TProcess.Create(nil);
   AStringList := TStringList.Create;
   Try
-  AProcess.Executable := 'cat';
-  AProcess.Parameters.Add('/proc/version');
+  AProcess.Executable := 'uname';
+  AProcess.Parameters.Add('-srm');
   AProcess.Options := AProcess.Options + [poWaitOnExit, poUsePipes];
   AProcess.Execute;
   AStringList.LoadFromStream(AProcess.Output);
   for i:=0 to pred(AStringList.Count) do
     writeln(AStringList[i]);
   except
-    writeln('Could not get Linux version! [tried: cat /proc/version]');
+    writeln('Could not get FreeBSD version! [tried: uname -srm]');
   end;
   AStringList.Free;
   AProcess.Free;
@@ -3249,12 +3249,12 @@ begin
   Writeln(ExtractFilePath(Paramstr(0))  + 'mysqld');
   if FileExistsUTF8(ExtractFilePath(Paramstr(0))  + 'mysqld') then
     Result := ExtractFilePath(Paramstr(0))  + 'mysqld';
-  if FileExistsUTF8('/usr/bin/mysqld') then
-    Result := '/usr/bin/mysqld';
-  if FileExistsUTF8('/usr/bin/mysqld_safe') then //Fedora
-    Result := '/usr/bin/mysqld_safe';
-  if FileExistsUTF8('/usr/sbin/mysqld') then //openSUSE
-    Result := '/usr/sbin/mysqld';
+   if FileExistsUTF8('/usr/local/bin/mysqld') then
+    Result := '/usr/local/bin/mysqld';
+  if FileExistsUTF8('/usr/local/bin/mysqld_safe') then //Fedora
+    Result := '/usr/local/bin/mysqld_safe';
+  if FileExistsUTF8('/usr/local/sbin/mysqld') then //openSUSE
+    Result := '/usr/local/sbin/mysqld';
   if Result = '' then  //don't know where mysqld is, so hopefully will be in  $PATH
     Result := 'mysqld'
 end;
