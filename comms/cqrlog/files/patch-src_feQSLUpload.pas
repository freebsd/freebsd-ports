--- src/feQSLUpload.pas.orig	2026-08-31 01:45:44 UTC
+++ src/feQSLUpload.pas
@@ -108,7 +108,7 @@ begin
   try try
     Rewrite(f);
     Writeln(f);
-    Writeln(f, 'ADIF export from CQRLOG for Linux version '+dmData.VersionString);
+    Writeln(f, 'ADIF export from CQRLOG for FreeBSD/Linux version '+dmData.VersionString);
     Writeln(f, 'Copyright (C) ',YearOf(now),' by Petr, OK2CQR and Martin, OK1RR');
     Writeln(f);
     Writeln(f, 'Internet: http://www.cqrlog.com');
