--- src/u_compilers.pas	2017-07-14 05:55:36 UTC
+++ src/u_compilers.pas
@@ -674,6 +674,7 @@ begin
       fPaths.DmdPhobosPath := path + '\src\phobos';
   end;
   {$ENDIF}
+  {$IFDEF UNIX}
   {$IFDEF LINUX}
   if '/usr/bin/dmd'.fileExists then
     fPaths.DmdExeName:='/usr/bin/dmd';
@@ -682,6 +683,15 @@ begin
   if '/usr/include/dmd/phobos'.dirExists then
     fPaths.DmdPhobosPath:='/usr/include/dmd/phobos';
   {$ENDIF}
+  {$IFDEF BSD}
+  if '%%LOCALBASE%%/bin/dmd'.fileExists then
+    fPaths.DmdExeName:='%%LOCALBASE%%/bin/dmd';
+  if '%%LOCALBASE%%/include/dmd/druntime/import'.dirExists then
+    fPaths.DmdRuntimePath:='%%LOCALBASE%%/include/dmd/druntime/import';
+  if '%%LOCALBASE%%/include/dmd/phobos'.dirExists then
+    fPaths.DmdPhobosPath:='%%LOCALBASE%%/include/dmd/phobos';
+  {$ENDIF}
+  {$ENDIF}
   {$IFDEF DARWIN}
   if '/usr/local/bin/dmd'.fileExists then
     fPaths.DmdExeName:='/usr/local/bin/dmd';
@@ -703,7 +713,11 @@ begin
     fPaths.GdcExeName:= path;
     str := TStringList.Create;
     try
-      path := path.extractFileDir.extractFilePath;
+{$IFDEF BSD}
+      path:= path.extractFileDir.extractFilePath+'/include';
+{$ELSE}
+      path:= path.extractFileDir.extractFilePath;
+{$ENDIF}
       FindAllDirectories(str, path, true);
       for path in str do
         if pos('include' + DirectorySeparator + 'd', path) > 0 then
@@ -729,11 +743,15 @@ begin
     fPaths.LdcExeName:= path;
     str := TStringList.Create;
     try
-      path := path.extractFileDir.extractFilePath;
+{$IFDEF BSD}
+      path:= path.extractFileDir.extractFilePath+'/include';
+{$ELSE}
+      path:= path.extractFileDir.extractFilePath;
+{$ENDIF}
       FindAllDirectories(str, path, true);
       for path in str do
       begin
-        i := pos('import' + DirectorySeparator + 'ldc', path);
+        i := pos('d' + DirectorySeparator + 'ldc', path);
         if i > 0 then
         begin
           fPaths.LdcRuntimePath:= path[1..i + 5];
