--- llvm/tools/sancov/sancov.cpp.orig	2023-01-12 07:12:30 UTC
+++ llvm/tools/sancov/sancov.cpp
@@ -529,10 +529,10 @@ class Ignorelists { (private)
       return std::unique_ptr<SpecialCaseList>();
 
     if (!ClBlacklist.empty())
-      return SpecialCaseList::createOrDie({{ClBlacklist}},
+      return SpecialCaseList::createOrDie({{ClBlacklist.getValue()}},
                                           *vfs::getRealFileSystem());
 
-    return SpecialCaseList::createOrDie({{ClIgnorelist}},
+    return SpecialCaseList::createOrDie({{ClIgnorelist.getValue()}},
                                         *vfs::getRealFileSystem());
   }
   std::unique_ptr<SpecialCaseList> DefaultIgnorelist;
