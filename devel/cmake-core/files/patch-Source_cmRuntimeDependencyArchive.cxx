Use the mostly compatible implementation of cmBinUtilsLinux* to enable keywords
like RUNTIME_DEPENDENCY_SET and RUNTIME_DEPENDENCIES in the install() command
and GET_RUNTIME_DEPENDENCIES in the file() command. This should be considered
experimental as the regression tests fail, but only due to minor string
mismatches. At the moment, it seems to work for our purposes, until more
real-life examples come in.

PR: 274275
See also: https://gitlab.kitware.com/cmake/cmake/-/issues/25305

--- Source/cmRuntimeDependencyArchive.cxx.orig	2023-09-20 14:33:04 UTC
+++ Source/cmRuntimeDependencyArchive.cxx
@@ -153,9 +153,11 @@ bool cmRuntimeDependencyArchive::Prepare()
       platform = "macos+macho";
     } else if (systemName == "Linux") {
       platform = "linux+elf";
+    } else if (systemName == "FreeBSD") {
+      platform = "freebsd+elf";
     }
   }
-  if (platform == "linux+elf") {
+  if (platform == "linux+elf" || platform == "freebsd+elf") {
     this->Linker = cm::make_unique<cmBinUtilsLinuxELFLinker>(this);
   } else if (platform == "windows+pe") {
     this->Linker = cm::make_unique<cmBinUtilsWindowsPELinker>(this);
@@ -403,6 +405,6 @@ bool cmRuntimeDependencyArchive::PlatformSupportsRunti
   const std::string& platform)
 {
   static const std::set<std::string> supportedPlatforms = { "Windows", "Linux",
-                                                            "Darwin" };
+                                                            "Darwin", "FreeBSD" };
   return supportedPlatforms.count(platform);
 }
