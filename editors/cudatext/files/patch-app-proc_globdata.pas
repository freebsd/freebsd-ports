--- app/proc_globdata.pas	2019-12-25 06:22:53.000000000 -0500
+++ app/proc_globdata.pas	2019-12-31 02:48:45.328993000 -0500
@@ -916,6 +916,9 @@
   Result:=
     {$ifdef linux} 
     '/usr/share/cudatext'
+    {$endif}
+    {$ifdef freebsd}
+    '%%DATADIR%%'
     {$else} 
       {$ifdef darwin} 
       ExtractFileDir(OpDirExe)+'/Resources'
@@ -986,6 +989,10 @@
   OpDirLocal:= AppDir_Home+'Library/Application Support/CudaText';
   CreateDirUTF8(OpDirLocal);
   {$endif}
+  {$ifdef freebsd}
+  OpDirLocal:= AppDir_Home + '.config/' + 'cudatext';
+  CreateDirUTF8(OpDirLocal);
+  {$endif}
 
   AppDir_Settings:= OpDirLocal+DirectorySeparator+'settings';
   CreateDirUTF8(AppDir_Settings);
@@ -1001,6 +1008,15 @@
           '/usr/share/cudatext/data',
           '/usr/share/cudatext/settings_default'
           ], S);
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
   {$ifdef darwin}
   if IsDistroUpdateNeeded then
