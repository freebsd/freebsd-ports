--- hphp/runtime/vm/repo.cpp.orig	2013-07-22 20:34:07.689418184 +0200
+++ hphp/runtime/vm/repo.cpp	2013-07-22 20:34:29.924423584 +0200
@@ -216,7 +216,7 @@
 
 std::string Repo::table(int repoId, const char* tablePrefix) {
   std::stringstream ss;
-  ss << dbName(repoId) << "." << tablePrefix << "_" << kRepoSchemaId;
+  ss << dbName(repoId) << "_" << tablePrefix << "_" << kRepoSchemaId;
   return ss.str();
 }
 
