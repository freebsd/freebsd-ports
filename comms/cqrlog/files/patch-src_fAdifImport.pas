--- src/fAdifImport.pas.orig	2026-08-31 01:43:41 UTC
+++ src/fAdifImport.pas
@@ -1056,7 +1056,7 @@ begin
     AssignFile(f,dmData.UsrHomeDir + ERR_FILE);
     Rewrite(f);
     Writeln(f);
-    Writeln(f,'ADIF export from CQRLOG for Linux version ' + dmData.VersionString);
+    Writeln(f,'ADIF export from CQRLOG for FreeBSD/Linux version ' + dmData.VersionString);
     Writeln(f,'Copyright (C) ',YearOf(now),' by Petr, OK2CQR and Martin, OK1RR');
     Writeln(f,'Internet: http://www.cqrlog.com');
     Writeln(f,'');
