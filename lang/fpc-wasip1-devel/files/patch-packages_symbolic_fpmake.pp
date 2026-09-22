--- packages/symbolic/fpmake.pp.orig	2026-09-21 22:25:49 UTC
+++ packages/symbolic/fpmake.pp
@@ -45,9 +45,6 @@ begin
     P.Targets.AddExampleProgram('evaltest.pas');
     P.Targets.AddExampleProgram('rpnthing.pas');
     P.Targets.AddExampleProgram('easyevalexample.pp');
-    P.Sources.AddDoc('doc/optimization.txt');
-    P.Sources.AddDoc('doc/symbolic.txt');
-
 
     P.NamespaceMap:='namespaces.lst';
 
