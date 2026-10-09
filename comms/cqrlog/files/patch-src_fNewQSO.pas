--- src/fNewQSO.pas.orig	2026-10-01 09:48:26.954449000 -0700
+++ src/fNewQSO.pas	2026-10-01 09:49:04.476476000 -0700
@@ -7247,7 +7247,7 @@
   exit;
   AProcess := TProcess.Create(nil);
   try
-    AProcess.Executable := 'bash';
+    AProcess.Executable := '/bin/sh';
     index:=0;
     paramList := TStringList.Create;
     paramList.Delimiter := ' ';
@@ -7283,7 +7283,7 @@
   
   AProcess := TProcess.Create(nil);
   try
-    AProcess.Executable := 'bash';
+    AProcess.Executable := '/bin/sh';
     AProcess.Parameters.Clear;
     AProcess.Parameters.Add(dmData.HomeDir + cVoiceKeyer);
     AProcess.Parameters.Add(key_pressed);
