--- src/fExportProgress.pas.orig	2026-08-31 01:46:18 UTC
+++ src/fExportProgress.pas
@@ -447,7 +447,7 @@ begin   //TfrmExportProgress
   Rewrite(f);
   System.SetTextBuf(f, TextBuf, SizeOf(TextBuf));   // 64 KB buffer -> fewer write() syscalls
   Writeln(f);
-  Writeln(f, 'ADIF export from CQRLOG for Linux version '+dmData.VersionString);
+  Writeln(f, 'ADIF export from CQRLOG for FreeBSD/Linux version '+dmData.VersionString);
   Writeln(f, 'Copyright (C) ',YearOf(now),' by Petr, OK2CQR and Martin, OK1RR');
   Writeln(f);
   Writeln(f, 'Internet: http://www.cqrlog.com');
