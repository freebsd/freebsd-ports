--- src/dData.pas.orig	2026-09-25 09:42:16.000000000 -0700
+++ src/dData.pas	2026-10-01 09:43:35.587833000 -0700
@@ -314,6 +314,8 @@
     procedure LoadMasterSCP;
     procedure RepairTables(nr : Word);
     procedure CreateQSLTmpTable;
+    procedure CreateLocalUser;
+    procedure InitializeMysqldProcess;
     procedure StartMysqldProcess;
     procedure RemoveeQSLUploadedFlag(id : Integer);
     procedure RemoveLoTWUploadedFlag(id : Integer);
@@ -512,7 +514,11 @@
     begin
       con.CharSet      := 'UTF8';
       con.HostName     := host;
-      con.Params.Text  := 'Port='+port+LineEnding+sslParam;
+      con.Params.Text  := 'Port='+port;
+
+      if (host <> '127.0.0.1') then
+        con.Params.Text  := 'Port='+port+LineEnding+sslParam;
+
       con.UserName     := user;
       con.Password     := pass;
       con.DatabaseName := 'information_schema';
@@ -914,22 +920,22 @@
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
@@ -954,7 +960,7 @@
 var
   s,d : String;
 begin
-  s := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+PathDelim+'ctyfiles'+PathDelim);
+  s := ExpandFileNameUTF8('%%DATADIR%%'+PathDelim+'ctyfiles'+PathDelim);
   d := fHomeDir+'ctyfiles'+PathDelim;
 
   if not FileExistsUTF8(fHomeDir+'ctyfiles'+PathDelim+'AreaOK1RR.tbl') then
@@ -1027,7 +1033,7 @@
 var
   s,d : String;
 begin
-  s := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+PathDelim+'xplanet'+PathDelim);
+  s := ExpandFileNameUTF8('%%DATADIR%%'+PathDelim+'xplanet'+PathDelim);
   d := fHomeDir+'xplanet'+PathDelim;
   if not FileExistsUTF8(d+'geoconfig') then
     CopyFile(s+'geoconfig',d+'geoconfig')
@@ -1037,7 +1043,7 @@
 var
   s,d : String;
 begin
-  s := ExpandFileNameUTF8('..'+PathDelim+'share'+PathDelim+'cqrlog'+PathDelim+'voice_keyer'+PathDelim);
+  s := ExpandFileNameUTF8('%%DATADIR%%'+PathDelim+'voice_keyer'+PathDelim);
   d := fHomeDir+'voice_keyer'+PathDelim;
   if not FileExistsUTF8(d+'voice_keyer.sh') then
     CopyFile(s+'voice_keyer.sh',d+'voice_keyer.sh')
@@ -1107,15 +1113,20 @@
   AProcess := TProcess.Create(nil);
   AStringList := TStringList.Create;
   Try
+{$IFDEF FREEBSD}
+  AProcess.Executable := 'uname';
+  AProcess.Parameters.Add('-a');
+{$ELSE}
   AProcess.Executable := 'cat';
   AProcess.Parameters.Add('/proc/version');
+{$ENDIF}
   AProcess.Options := AProcess.Options + [poWaitOnExit, poUsePipes];
   AProcess.Execute;
   AStringList.LoadFromStream(AProcess.Output);
   for i:=0 to pred(AStringList.Count) do
     writeln(AStringList[i]);
   except
-    writeln('Could not get Linux version! [tried: cat /proc/version]');
+    writeln('Could not get FreeBSD/Linux version! [tried: cat /proc/version or uname -a]');
   end;
   AStringList.Free;
   AProcess.Free;
@@ -1148,7 +1159,25 @@
     end;
   end;
   {$ENDIF}
+  {$IFDEF FREEBSD}
+  begin
+    lib := '';
+    if FileExists('%%LOCALBASE%%/lib/mysql/libmysqlclient.so') then
+      lib := '%%LOCALBASE%%/lib/mysql/libmysqlclient.so';
 
+    if lib <> '' then
+    begin
+      try
+        InitialiseMysql(lib);
+        Writeln('MySQL library loaded from: ', lib);
+      except
+        on E: Exception do
+          Writeln('Note: Could not preload MySQL library from ', lib, ': ', E.Message);
+      end;
+    end;
+  end;
+  {$ENDIF}
+
   CreateDBConnections;
 
   MainCon.KeepConnection := True;
@@ -2786,12 +2815,14 @@
     '/usr/local/bin/mariadbd',
     '/usr/local/bin/mysqld');
   {$ENDIF}
-  cServerPaths : array[0..6] of String = (
+  cServerPaths : array[0..8] of String = (
     '/usr/sbin/mariadbd',      //Debian, Ubuntu
     '/usr/sbin/mysqld',        //openSUSE, Debian symlink
     '/usr/bin/mysqld_safe',    //Fedora
     '/usr/bin/mariadbd-safe',  //Fedora without the mysql symlinks
     '/usr/libexec/mariadbd',   //Fedora, RHEL
+    '%%LOCALBASE%%/libexec/mariadbd',   //FreeBSD
+    '%%LOCALBASE%%/libexec/mysqld',   //FreeBSD
     '/usr/bin/mariadbd',       //Arch
     '/usr/bin/mysqld');
 var
@@ -2817,9 +2848,9 @@
   l : TStringList;
   i : Integer;
 begin
-  if not FileExistsUTF8(fHomeDir+'database'+DirectorySeparator+'mysql.cnf') then
+  if not FileExistsUTF8(fHomeDir+'mysql.cnf') then
   begin
-    AssignFile(f,fHomeDir+'database'+DirectorySeparator+'mysql.cnf');
+    AssignFile(f,fHomeDir+'mysql.cnf');
     Rewrite(f);
     Writeln(f,scMySQLConfig.Script.Text);
     CloseFile(f)
@@ -2832,12 +2863,12 @@
 
     l := TStringList.Create;
     try try
-      l.LoadFromFile(fHomeDir+'database'+DirectorySeparator+'mysql.cnf');
+      l.LoadFromFile(fHomeDir+'mysql.cnf');
       i := l.IndexOf('innodb_additional_mem_pool_size=1M');
       if i > -1 then
       begin
         l.Strings[i] := '#innodb_additional_mem_pool_size=1M';
-        l.SaveToFile(fHomeDir+'database'+DirectorySeparator+'mysql.cnf')
+        l.SaveToFile(fHomeDir+'mysql.cnf')
       end
     except
       on E : Exception do
@@ -2847,6 +2878,78 @@
       FreeAndNil(l);
     end
   end
+end;
+
+procedure TdmData.CreateLocalUser;   //"create_cqr_local_user.sh"
+var
+  UsrHome: string;
+  f: TextFile;
+begin
+  UsrHome := dmUtils.GetHomeDirectory;
+
+  AssignFile(f, UsrHome + 'create_cqr_local_user.sh');
+  rewrite(f);
+  Writeln(f, '#!/bin/sh');
+  Writeln(f);
+  Writeln(f, 'echo -e "\nCreating user cqrlog@localhost for CQRLOG use\n"');
+  Writeln(f, 'mysql -u root -P64000 -h127.0.0.1 <<EOFSQL');
+  Writeln(f, 'CREATE USER IF NOT EXISTS ' + #$27 + 'cqrlog' + #$27 + '@' + #$27 +
+    'localhost' + #$27 + ' IDENTIFIED BY ' + #$27 + 'cqrlog' + #$27 + ';');
+  Writeln(f, 'GRANT ALL PRIVILEGES ON *.* TO ' + #$27 + 'cqrlog' + #$27 + '@' +
+    #$27 + 'localhost' + #$27 + ';');
+  Writeln(f, 'FLUSH PRIVILEGES;');
+  Writeln(f, 'EOFSQL');
+  Writeln(f);
+  Writeln(f, 'status=$?');
+  Writeln(f, '[ $status -eq 0 ] && echo -e "\nUser creation SUCCESS !"');
+  Writeln(f, '[ $status -eq 0 ] && echo $status > /tmp/cqrSQLLocalUsrCreate');
+  Writeln(f, '[ $status -ne 0 ] && echo -e "\nUser creation FAILED !\n\nCheck error !" && exit 1');
+  Writeln(f, 'echo Done! > '+fHomeDir+'cqrCreateLocalUsrDone');
+  Writeln(f, 'exit $status');
+  closeFile(f);
+  dmUtils.ExecuteCommand('chmod a+rwx ' + UsrHome + 'create_cqr_local_user.sh');
+  dmUtils.ExecuteCommand('sh ' + UsrHome + 'create_cqr_local_user.sh');
+end;
+
+procedure TdmData.InitializeMysqldProcess;
+var
+  mysqld    : String;
+  index     :integer;
+  paramList :TStringList;
+begin
+  mysqld := GetMysqldPath;
+
+  MySQLProcess := TProcess.Create(nil);
+  MySQLProcess.Executable := mysqld;
+  index:=0;
+    
+  if not FileExists(fDataDir+'/ibdata1') then
+  begin    
+    paramList := TStringList.Create;
+    paramList.Delimiter := ' ';
+    paramList.DelimitedText := (' --defaults-file='+fHomeDir+'mysql.cnf'+
+                                ' --datadir='+fHomeDir+'database/'+
+                                ' --socket='+fHomeDir+'database/sock'+
+                                ' --port=64000'+
+                                ' --bind-address=127.0.0.1'+
+                                ' --initialize-insecure');
+    MySQLProcess.Parameters.Clear;
+    while index < paramList.Count do
+    begin
+      MySQLProcess.Parameters.Add(paramList[index]);
+      inc(index);
+    end;
+    paramList.Free;
+
+    if dmData.DebugLevel>=1 then Writeln('MySQLProcess.Executable: ',MySQLProcess.Executable,' Parameters: ',MySQLProcess.Parameters.Text);
+    MySQLProcess.Execute;
+    MySQLProcess.WaitOnExit;
+
+    if MySQLProcess.ExitStatus = 0 then
+      writeln('Initialization complete');
+  end;
+
+  MySQLProcess.Free
 end;
 
 procedure TdmData.StartMysqldProcess;
@@ -2856,19 +2959,22 @@
   Tryies    : Word = 0;
   index     :integer;
   paramList :TStringList;
-
 begin
   mysqld := GetMysqldPath;
   PrepareMysqlConfigFile;
+  InitializeMysqldProcess;
   MySQLProcess := TProcess.Create(nil);
   MySQLProcess.Executable := mysqld;
   index:=0;
+
   paramList := TStringList.Create;
   paramList.Delimiter := ' ';
-  paramList.DelimitedText := (' --defaults-file='+fHomeDir+'database/'+'mysql.cnf'+
+  paramList.DelimitedText := (' --defaults-file='+fHomeDir+'mysql.cnf'+
                               ' --datadir='+fHomeDir+'database/'+
                               ' --socket='+fHomeDir+'database/sock'+
+                              ' --bind-address=127.0.0.1'+
                               ' --port=64000');
+
   MySQLProcess.Parameters.Clear;
   while index < paramList.Count do
   begin
@@ -2884,36 +2990,46 @@
     MainCon.Connected := False;
 
   MainCon.HostName     := '127.0.0.1';
-  MainCon.Params.Text  := 'Port=64000'+LineEnding+cDBSSLNoVerify;
+  MainCon.Params.Text  := 'Port=64000';
   MainCon.DatabaseName := 'information_schema';
   MainCon.UserName     := 'cqrlog';
   MainCon.Password     := 'cqrlog';
 
-  while true do
+  Tryies := 0;
+  Connected := False;
+
+  while (not Connected) and (Tryies < 10) do
   begin
-    try try
-      Connected := True;
-      inc(Tryies);
-      MainCon.Connected := True
+    Inc(Tryies);
+
+    try
+      MainCon.Connected := True;
+      Connected := MainCon.Connected;
+
+      if fDebugLevel >= 1 then
+        Writeln('MySQL connected on attempt ', Tryies);
+
     except
-      on E : Exception do
+      on E: Exception do
       begin
-        if fDebugLevel>=1 then Writeln('Trying to connect to database');
-        Sleep(1000);
         Connected := False;
-        if fDebugLevel>=1 then Writeln(E.Message);
-        if fDebugLevel>=1 then Writeln('Trying:',Tryies);
-	if (Tryies > 7) then
-	  Break
-	else
-          Continue
-      end
-    end
-    finally
-      MainCon.Connected := False
-    end;
-    if Connected or (Tryies>5) then break
+
+        if fDebugLevel >= 1 then
+        begin
+          Writeln(E.Message);
+          Writeln('Waiting for MySQL... attempt ', Tryies);
+        end;
+
+        if Tryies < 10 then
+        begin
+          Sleep(1000);
+          if not FileExists(fHomeDir+'cqrCreateLocalUsrDone') then
+            CreateLocalUser;
+        end;
+      end;
+    end;
   end;
+
   MainCon.DatabaseName := '';
   if not Connected then
   begin
