--- src/fDbSqlSel.pas.orig	2026-09-25 09:42:16.000000000 -0700
+++ src/fDbSqlSel.pas	2026-10-01 10:53:18.626873000 -0700
@@ -138,7 +138,7 @@
 
   AssignFile(f, UsrHome + 'create_cqr_user.sh');
   rewrite(f);
-  Writeln(f, '#!/bin/bash');
+  Writeln(f, '#!/bin/sh');
   Writeln(f);
   Writeln(f, 'echo -e "\nCreating user ' + user + '@localhost for CQRLOG use\n"');
   Writeln(f, 'sudo -p "Give user %u password for sudo: " mysql<<EOFSQL');
@@ -170,7 +170,7 @@
 
   AssignFile(f, UsrHome + 'backup_all_cqr.sh');
   rewrite(f);
-  Writeln(f, '#!/bin/bash');
+  Writeln(f, '#!/bin/sh');
   Writeln(f);
   Writeln(f, 'stamp=$(date +_%Y%m%d-%H%M)');
   Writeln(f, 'echo -e "\nStarted$stamp"');
@@ -192,7 +192,7 @@
 
 
   Writeln(f, 'echo -e "\nDone!\nCopy backup files to your safe place.\n'+
-             'They will be erased from /tmp at next Linux start\n\n"');
+             'They will be erased from /tmp at next FreeBSD/Linux start\n\n"');
   Writeln(f, 'echo "To restore all CQRLOG logs use command:"');
   Writeln(f, 'echo -e "mysql -h' + ip + ' -P' + port + ' -u' + user + ' -p' + pass +
              ' < /tmp/allcqrlogs$stamp.sql\n\n"');
@@ -304,7 +304,7 @@
     //set values to database connect and exit
     MakeScript1;
     MakeScript2;
-    ExecuteScript;
+    //ExecuteScript;
   end;
 
   btnOK.Visible := False;
