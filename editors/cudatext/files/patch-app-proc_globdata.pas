--- app/proc_globdata.pas	2018-04-19 12:59:47.000000000 -0500
+++ app/proc_globdata.pas	2018-04-25 21:26:43.609078000 -0500
@@ -745,7 +745,7 @@
   Result:=
   {$ifdef windows} '' {$endif}
   {$ifdef linux} '/usr/share/cudatext' {$endif}
-  {$ifdef freebsd} '' {$endif}
+  {$ifdef freebsd} '%%DATADIR%%' {$endif}
   {$ifdef darwin} ExtractFileDir(OpDirExe)+'/Resources' {$endif}
 end;
 
@@ -895,6 +895,15 @@
         '/usr/share/cudatext/settings_default'
         ], S);
       {$endif}
+      {$ifdef freebsd}
+      RunCommand('cp', ['-R',
+        '%%DATADIR%%/py',
+        '%%DATADIR%%/data',
+        '%%DATADIR%%/readme',
+        '%%DATADIR%%/settings_default',
+        OpDirLocal
+        ], S);
+      {$endif}
       {$ifdef darwin}
       //see rsync help. need options:
       // -u (update)
