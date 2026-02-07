--- app/proc_globdata.pas.orig	2025-01-12 09:06:24.000000000 -0800
+++ app/proc_globdata.pas	2025-01-24 13:45:23.584690000 -0800
@@ -1406,7 +1406,7 @@
   {$endif}
 
   {$ifdef freebsd}
-  exit('/usr/local/lib/libpython3.6m.so');
+  exit('%%LOCALBASE%%/lib/libpython3.11.so');
   {$endif}
 
   {$ifdef openbsd}
@@ -1456,6 +1456,10 @@
   exit(ExtractFileDir(OpDirExe)+'/Resources');
   {$endif}
 
+  {$ifdef freebsd}
+  exit('%%DATADIR%%');
+  {$endif}
+
   Result:= '';
 end;
 
@@ -1597,6 +1601,16 @@
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
@@ -1656,8 +1670,10 @@
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
@@ -1726,6 +1742,15 @@
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
