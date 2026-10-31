--- app/proc_globdata.pas.orig	2026-10-28 14:12:01 UTC
+++ app/proc_globdata.pas
@@ -1493,7 +1493,7 @@ begin
   {$endif}
 
   {$ifdef freebsd}
-  exit('/usr/local/lib/libpython3.6m.so');
+  exit('%%LOCALBASE%%/lib/libpython3.11.so');
   {$endif}
 
   {$ifdef openbsd}
@@ -1543,6 +1543,10 @@ begin
   exit(ExtractFileDir(OpDirExe)+'/Resources');
   {$endif}
 
+  {$ifdef freebsd}
+  exit('%%DATADIR%%');
+  {$endif}
+
   Result:= '';
 end;
 
@@ -1698,6 +1702,16 @@ end;
   CreateDir(OpDirLocal);
 end;
 
+procedure InitDirs_FreeBSD;
+var
+  HomeConfig: string;
+begin
+  AppDir_Home:= GetEnvironmentVariable('HOME');
+  HomeConfig:= AppDir_Home+'/.config';
+  OpDirLocal:= HomeConfig+'/cudatext';
+  CreateDir(OpDirLocal);
+end;
+
 procedure InitDirs_UnixCommon;
 var
   HomeConfig: string;
@@ -1757,8 +1771,10 @@ begin
     {$ifdef darwin}
     InitDirs_macOS;
     {$else}
-      {$ifdef haiku}
+      {$if defined(haiku)}
       InitDirs_Haiku;
+      {$elseif defined(freebsd)}
+      InitDirs_FreeBSD;
       {$else}
       InitDirs_UnixCommon;
       {$endif}
@@ -1829,6 +1845,15 @@ begin
       MsgLogConsole('ERROR: Cannot find pre-copy folder: '+OpDirPrecopy);
     end;
   end;
+  {$endif}
+  {$ifdef freebsd}
+    RunCommand('cp', ['-R',
+        '%%DATADIR%%/py',
+        '%%DATADIR%%/data',
+        '%%DATADIR%%/readme',
+        '%%DATADIR%%/settings_default',
+        OpDirLocal
+         ], S);
   {$endif}
 
   AppDir_Py:= OpDirLocal+DirectorySeparator+'py';
