--- packages/pastojs/fpmake.pp	2020-10-04 00:18:21.474418000 -0500
+++ packages/pastojs/fpmake.pp	2020-10-04 00:18:32.337561000 -0500
@@ -57,6 +57,11 @@
     T:=P.Targets.AddUnit('pas2jspparser.pp');
     T:=P.Targets.AddUnit('pas2jsuseanalyzer.pp');
     T:=P.Targets.AddUnit('pas2jscompiler.pp');
+    T:=P.Targets.AddUnit('pas2jsresstrfile.pp');
+    T.ResourceStrings := True;
+    T:=P.Targets.AddUnit('pas2jsresources.pp');
+    T:=P.Targets.AddUnit('pas2jshtmlresources.pp');
+    T:=P.Targets.AddUnit('pas2jsjsresources.pp');
     T:=P.Targets.AddUnit('pas2jsfscompiler.pp');
       T.Dependencies.AddUnit('pas2jscompiler');
     T:=P.Targets.AddUnit('pas2jspcucompiler.pp');
