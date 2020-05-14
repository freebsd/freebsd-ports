--- app/proc_globdata.pas	2020-05-11 23:45:28.000000000 -0500
+++ app/proc_globdata.pas	2020-05-13 18:40:54.377841000 -0500
@@ -909,6 +909,10 @@
   exit(ExtractFileDir(OpDirExe)+'/Resources');
   {$endif}
 
+  {$ifdef freebsd}
+  exit('%%DATADIR%%');
+  {$endif}
+
   Result:= '';
 end;
 
@@ -973,6 +977,10 @@
   OpDirLocal:= AppDir_Home+'Library/Application Support/CudaText';
   CreateDirUTF8(OpDirLocal);
   {$endif}
+  {$ifdef freebsd}
+  OpDirLocal:= AppDir_Home + '.config/' + 'cudatext';
+  CreateDirUTF8(OpDirLocal);
+  {$endif}
 
   AppDir_Settings:= OpDirLocal+DirectorySeparator+'settings';
   CreateDirUTF8(AppDir_Settings);
@@ -1000,6 +1008,15 @@
         OpDirPrecopy+'/',
         OpDirLocal
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
 
   AppDir_Py:= OpDirLocal+DirectorySeparator+'py';
