FreeBSD's ldconfig(8) is largely incompatible with that from glibc. Ignore
these extra paths and just rely on those provided by objdump(1).

--- Source/cmBinUtilsLinuxELFLinker.cxx.orig	2023-12-06 13:57:42 UTC
+++ Source/cmBinUtilsLinuxELFLinker.cxx
@@ -65,6 +65,7 @@ bool cmBinUtilsLinuxELFLinker::Prepare()
     return false;
   }
 
+#if defined(__linux__)
   std::string ldConfigTool =
     this->Archive->GetMakefile()->GetSafeDefinition("CMAKE_LDCONFIG_TOOL");
   if (ldConfigTool.empty()) {
@@ -82,6 +83,7 @@ bool cmBinUtilsLinuxELFLinker::Prepare()
     this->SetError(e.str());
     return false;
   }
+#endif
 
   return true;
 }
@@ -135,8 +137,10 @@ bool cmBinUtilsLinuxELFLinker::ScanDependencies(
                        parentRpaths.end());
   }
 
+#if defined(__linux__)
   searchPaths.insert(searchPaths.end(), this->LDConfigPaths.begin(),
                      this->LDConfigPaths.end());
+#endif
 
   for (auto const& dep : needed) {
     if (!this->Archive->IsPreExcluded(dep)) {
