FreeBSD's ldconfig(8) is largely incompatible with that from glibc. Ignore
these extra paths and just rely on those provided by objdump(1).

--- Source/cmBinUtilsLinuxELFLinker.cxx.orig	2024-11-06 13:41:37 UTC
+++ Source/cmBinUtilsLinuxELFLinker.cxx
@@ -68,6 +68,7 @@ bool cmBinUtilsLinuxELFLinker::Prepare()
     return false;
   }
 
+#if defined(__linux__)
   std::string ldConfigTool =
     this->Archive->GetMakefile()->GetSafeDefinition("CMAKE_LDCONFIG_TOOL");
   if (ldConfigTool.empty()) {
@@ -85,6 +86,7 @@ bool cmBinUtilsLinuxELFLinker::Prepare()
     this->SetError(e.str());
     return false;
   }
+#endif
 
   return true;
 }
@@ -145,8 +147,10 @@ bool cmBinUtilsLinuxELFLinker::ScanDependencies(std::s
                          parentRpaths.end());
     }
 
+#if defined(__linux__)
     searchPaths.insert(searchPaths.end(), this->LDConfigPaths.begin(),
                        this->LDConfigPaths.end());
+#endif
 
     for (auto const& dep : needed) {
       if (resolvedDependencies.count(dep) != 0 ||
