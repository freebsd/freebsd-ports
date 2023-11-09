FreeBSD's ldconfig(8) is largely incompatible with that from glibc. Ignore
these extra paths and just rely on those provided by objdump(1).

--- Source/cmBinUtilsLinuxELFLinker.cxx.orig	2023-10-07 19:03:44 UTC
+++ Source/cmBinUtilsLinuxELFLinker.cxx
@@ -132,12 +132,14 @@ bool cmBinUtilsLinuxELFLinker::ScanDependencies(
                        parentRpaths.end());
   }
 
+#if defined(__linux__)
   std::vector<std::string> ldConfigPaths;
   if (!this->LDConfigTool->GetLDConfigPaths(ldConfigPaths)) {
     return false;
   }
   searchPaths.insert(searchPaths.end(), ldConfigPaths.begin(),
                      ldConfigPaths.end());
+#endif
 
   for (auto const& dep : needed) {
     if (!this->Archive->IsPreExcluded(dep)) {
