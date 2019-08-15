--- app/proc_globdata.pas	2019-07-18 15:40:29.000000000 -0500
+++ app/proc_globdata.pas	2019-07-20 23:37:23.078548000 -0500
@@ -857,6 +857,9 @@
   Result:=
     {$ifdef linux} 
     '/usr/share/cudatext'
+    {$endif}
+    {$ifdef freebsd}
+    '%%DATADIR%%'
     {$else} 
       {$ifdef darwin} 
       ExtractFileDir(OpDirExe)+'/Resources'
@@ -1032,6 +1035,15 @@
         '/usr/share/cudatext/data',
         '/usr/share/cudatext/readme',
         '/usr/share/cudatext/settings_default'
+        ], S);
+      {$endif}
+      {$ifdef freebsd}
+      RunCommand('cp', ['-R',
+        '%%DATADIR%%/py',
+        '%%DATADIR%%/data',
+        '%%DATADIR%%/readme',
+        '%%DATADIR%%/settings_default',
+        OpDirLocal
         ], S);
       {$endif}
       {$ifdef darwin}
