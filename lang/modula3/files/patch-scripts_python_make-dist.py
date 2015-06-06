--- scripts/python/make-dist.py.orig	2015-06-03 20:58:25 UTC
+++ scripts/python/make-dist.py
@@ -172,8 +172,8 @@ def FatalError():
 InstallRoot_Previous = InstallRoot
 InstallRoot_CompilerWithPrevious = os.path.join(GetStage(), "compiler_with_previous")
 InstallRoot_CompilerWithSelf = os.path.join(GetStage(), "compiler_with_self")
-InstallRoot_Min = FormInstallRoot("min")
-InstallRoot_All = FormInstallRoot("all")
+InstallRoot_Min = os.path.join(GetStage(), "min-dist")
+InstallRoot_All = os.path.join(GetStage(), "all-dist");
 InstallRoots = [InstallRoot_Min, InstallRoot_All]
 
 OriginalLIB = os.getenv("LIB")
@@ -327,7 +327,7 @@ else:
 
 # ----------------------------------------------------------------------------------------------------------------------------------
 
-MakeArchives()
+InstallLicense(Root, InstallRoot_All)
 
 if contains(target, "linux"):
     MakeDebianPackage(FormInstallRoot("all"), "/usr/local/cm3")
