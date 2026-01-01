--- llvm/tools/sancov/sancov.cpp.orig	2023-11-28 08:52:28 UTC
+++ llvm/tools/sancov/sancov.cpp
@@ -518,7 +518,7 @@ class Ignorelists { (private)
   static std::unique_ptr<SpecialCaseList> createUserIgnorelist() {
     if (ClIgnorelist.empty())
       return std::unique_ptr<SpecialCaseList>();
-    return SpecialCaseList::createOrDie({{ClIgnorelist}},
+    return SpecialCaseList::createOrDie({{ClIgnorelist.getValue()}},
                                         *vfs::getRealFileSystem());
   }
   std::unique_ptr<SpecialCaseList> DefaultIgnorelist;
