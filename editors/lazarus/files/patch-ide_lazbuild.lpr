--- ide/lazbuild.lpr	2015-06-15 03:49:45.000000000 -0500
+++ ide/lazbuild.lpr	2015-06-15 03:50:20.000000000 -0500
@@ -436,7 +436,9 @@
     DoCreateMakefile(APackage)
   else
     CompilePackage(APackage,Flags);
-  
+
+  PkgLinks.SaveUserLinks(true);
+
   Result:=true;
 end;
 
