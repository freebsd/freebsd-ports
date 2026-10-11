Newer libc++ makes basic_string's string_view-like constructor explicit.
cl::opt<std::string> derives from std::string and converts to
std::string_view, so that template constructor is an exact match and wins
over the copy constructor, which breaks the copy-initialization inside the
initializer list.  Pass the stored std::string instead.

--- tools/sancov/sancov.cc.orig	2018-07-16 20:34:51 UTC
+++ tools/sancov/sancov.cc
@@ -611,7 +611,7 @@ private:
     if (ClBlacklist.empty())
       return std::unique_ptr<SpecialCaseList>();
 
-    return SpecialCaseList::createOrDie({{ClBlacklist}});
+    return SpecialCaseList::createOrDie({{ClBlacklist.getValue()}});
   }
   std::unique_ptr<SpecialCaseList> DefaultBlacklist;
   std::unique_ptr<SpecialCaseList> UserBlacklist;
