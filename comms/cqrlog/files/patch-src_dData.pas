--- src/dData.pas.orig	2016-04-20 16:06:15 UTC
+++ src/dData.pas
@@ -1278,12 +1278,12 @@ begin
 
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
 
@@ -3452,12 +3452,12 @@ var
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
