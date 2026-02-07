--- llvm/tools/sancov/sancov.cpp.orig	2021-06-28 16:23:38 UTC
+++ llvm/tools/sancov/sancov.cpp
@@ -509,7 +509,7 @@ class Blacklists { (private)
     if (ClBlacklist.empty())
       return std::unique_ptr<SpecialCaseList>();
 
-    return SpecialCaseList::createOrDie({{ClBlacklist}},
+    return SpecialCaseList::createOrDie({{ClBlacklist.getValue()}},
                                         *vfs::getRealFileSystem());
   }
   std::unique_ptr<SpecialCaseList> DefaultBlacklist;
