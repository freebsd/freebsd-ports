--- src/fMonWsjtx.pas.orig	2026-10-01 09:47:25.572760000 -0700
+++ src/fMonWsjtx.pas	2026-10-01 09:47:45.044986000 -0700
@@ -1877,7 +1877,7 @@
   if (myAlert <> '') and (timeToAlert <> msgTime) then
   begin
     timeToAlert := msgTime;
-    RunVA(myAlert); //play bash script
+    RunVA(myAlert); //play sh/bash script
   end;
 end;
 
@@ -2431,7 +2431,7 @@
         if LocalDbg then Writeln('Next create script wget + unzip');
         AssignFile(f,dmData.HomeDir+C_MY_SCRIPT);
         ReWrite(f);
-            Writeln(f,'#!/bin/bash');
+            Writeln(f,'#!/bin/sh');
             Writeln(f,'wget -q -nd -O'+dmData.HomeDir+C_MYZIP+' '+trim(FCC_Address));
             Writeln(f,'unzip -q -o -d'+dmData.HomeDir+'ctyfiles/ '+dmData.HomeDir+C_MYZIP+' EN.dat');
             Writeln(f,'exit');
@@ -2449,7 +2449,7 @@
     try
      try
       if LocalDbg then Writeln('Next DProcess run script');
-      DProcess.Executable  := '/bin/bash';
+      DProcess.Executable  := '/bin/sh';
       DProcess.Parameters.Add(dmData.HomeDir+C_MY_SCRIPT);
       if LocalDbg then Writeln('DProcess.Executable: ',DProcess.Executable,' Parameters: ',DProcess.Parameters.Text);
       DProcess.Execute;
