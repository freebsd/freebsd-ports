--- source/dbconnection.pas	2025-12-16 22:09:54.829290000 -0800
+++ source/dbconnection.pas	2025-12-16 22:11:26.512363000 -0800
@@ -231,10 +231,10 @@
   end;
   TDatabaseCache = class(TObjectList<TDBObjectList>); // A list of db object lists, used for caching
   TDBObjectComparer = class(TComparer<TDBObject>)
-    function Compare({$IF FPC_FULLVERSION<30204}constref{$ELSE}const{$ENDIF} Left, Right: TDBObject): Integer; override;
+    function Compare({$IF FPC_FULLVERSION<30203}constref{$ELSE}const{$ENDIF} Left, Right: TDBObject): Integer; override;
   end;
   TDBObjectDropComparer = class(TComparer<TDBObject>)
-    function Compare({$IF FPC_FULLVERSION<30204}constref{$ELSE}const{$ENDIF} Left, Right: TDBObject): Integer; override;
+    function Compare({$IF FPC_FULLVERSION<30203}constref{$ELSE}const{$ENDIF} Left, Right: TDBObject): Integer; override;
   end;
 
   TOidStringPairs = TDictionary<POid, String>;
@@ -1911,7 +1911,7 @@
   {$If defined(WINDOWS) OR defined(DARWIN)}
   DllPath, DllFile: String;
   Dlls: TStringList;
-  {$ElseIf defined(LINUX)}
+  {$ElseIf defined(LINUX) OR defined(FREEBSD)}
   LibMapOutput, LibMap: String;
   LibMapLines: TStringList;
   {$EndIf}
@@ -1926,9 +1926,11 @@
     rx.ModifierI := True;
     case NetTypeGroup of
       ngMySQL:
-        {$IfDef LINUX}
+        {$If defined(LINUX)}
         // libmariadb.so.0 (libc,...) => /lib/x86_64-linux-gnu/libmariadb.so
         rx.Expression := '^\s*lib(mysqlclient|mariadb|perconaserverclient)\.[^=]+=>\s*(\S+)$';
+        {$ElseIf defined(FREEBSD)}
+        rx.Expression := '(mysqlclient|mariadb|perconaserverclient)[^=]+=>\s*(\S+)$';
         {$Else}
         rx.Expression := '^lib(mysql|mariadb).*\.' + SharedSuffix;
         {$EndIf}
@@ -1939,14 +1941,18 @@
         rx.Expression := '^(dblib|libsybdb).*\.' + SharedSuffix;
         {$EndIf}
       ngPgSQL:
-        {$IfDef LINUX}
+        {$If defined(LINUX)}
         rx.Expression := '^\s*(libpq)[^=]+=>\s*(\S+)$';
+        {$ElseIf defined(FREEBSD)}
+        rx.Expression := '(lpq)[^=]+=>\s*(\S+)$';
         {$Else}
         rx.Expression := '^libpq.*\.' + SharedSuffix;
         {$EndIf}
       ngSQLite: begin
-        {$IfDef LINUX}
+        {$If defined(LINUX)}
         rx.Expression := '^\s*(libsqlite3)[^=]+=>\s*(\S+)$';
+        {$ElseIf defined(FREEBSD)}
+        rx.Expression := '(lsqlite3)[^=]+=>\s*(\S+)$';
         {$Else}
         if NetType = ntSQLite then
           rx.Expression := '^(lib)?sqlite.*\.' + SharedSuffix
@@ -1959,9 +1965,13 @@
     end;
     case NetTypeGroup of
       ngMySQL, ngMSSQL, ngPgSQL, ngSQLite, ngInterbase: begin
+        {$if defined(LINUX) or defined(FREEBSD)}
         {$IfDEF LINUX}
         // See https://serverfault.com/a/513938
         Process.RunCommandInDir('', '/sbin/ldconfig', ['-p'], LibMapOutput);
+        {$Else}
+        Process.RunCommandInDir('', '/sbin/ldconfig', ['-r'], LibMapOutput);
+        {$EndIf}
         LibMapLines := Explode(sLineBreak, LibMapOutput);
         for LibMap in LibMapLines do begin
           if rx.Exec(LibMap) and FileExists(rx.Match[2]) then begin
@@ -3301,6 +3311,11 @@
 begin
   // Init libmysql before actually connecting.
   LibraryPath := GetLibDir + Parameters.LibraryOrProvider;
+{$IF DEFINED(LINUX) OR DEFINED(FREEBSD)}
+  LibraryPath := Parameters.LibraryOrProvider;
+{$ELSE}
+  LibraryPath := ExtractFilePath(ParamStr(0)) + Parameters.LibraryOrProvider;
+{$ENDIF}
   Log(lcDebug, f_('Loading library file %s ...', [LibraryPath]));
   // Throws EDbError on any failure:
   FLib := TMySQLLib.Create(LibraryPath, Parameters.DefaultLibrary);
@@ -3315,7 +3330,11 @@
   msg: String;
 begin
   // Init lib before actually connecting.
-  LibraryPath := GetLibDir + Parameters.LibraryOrProvider;
+{$IF DEFINED(LINUX) OR DEFINED(FREEBSD)}
+  LibraryPath := Parameters.LibraryOrProvider;
+{$ELSE}
+  LibraryPath := ExtractFilePath(ParamStr(0)) + Parameters.LibraryOrProvider;
+{$ENDIF}
   Log(lcDebug, f_('Loading library file %s ...', [LibraryPath]));
   try
     FLib := TPostgreSQLLib.Create(LibraryPath, Parameters.DefaultLibrary);
@@ -3346,7 +3365,11 @@
   LibraryPath: String;
 begin
   // Init lib before actually connecting.
-  LibraryPath := GetLibDir + Parameters.LibraryOrProvider;
+{$IF DEFINED(LINUX) OR DEFINED(FREEBSD)}
+  LibraryPath := Parameters.LibraryOrProvider;
+{$ELSE}
+  LibraryPath := ExtractFilePath(ParamStr(0)) + Parameters.LibraryOrProvider;
+{$ENDIF}
   Log(lcDebug, f_('Loading library file %s ...', [LibraryPath]));
   // Throws EDbError on any failure:
   if Parameters.NetType = ntSQLite then
@@ -10238,14 +10261,14 @@
 
 { TDBObjectComparer }
 
-function TDBObjectComparer.Compare({$IF FPC_FULLVERSION<30204}constref{$ELSE}const{$ENDIF} Left, Right: TDBObject): Integer;
+function TDBObjectComparer.Compare({$IF FPC_FULLVERSION<30203}constref{$ELSE}const{$ENDIF} Left, Right: TDBObject): Integer;
 begin
   // Simple sort method for a TDBObjectList
   Result := CompareAnyNode(Left.Schema+'.'+Left.Name, Right.Schema+'.'+Right.Name);
 end;
 
 
-function TDBObjectDropComparer.Compare({$IF FPC_FULLVERSION<30204}constref{$ELSE}const{$ENDIF} Left, Right: TDBObject): Integer;
+function TDBObjectDropComparer.Compare({$IF FPC_FULLVERSION<30203}constref{$ELSE}const{$ENDIF} Left, Right: TDBObject): Integer;
 begin
   // Sorting a TDBObject items so that dropping them does not trap in SQL errors
   if (Left.NodeType = lntTrigger) and (Right.NodeType <> lntTrigger) then
