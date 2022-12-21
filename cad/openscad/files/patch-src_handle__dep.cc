- https://github.com/openscad/openscad/issues/4453

--- src/handle_dep.cc.orig	2022-12-20 00:11:57 UTC
+++ src/handle_dep.cc
@@ -9,6 +9,8 @@
 #include <boost/filesystem.hpp>
 namespace fs = boost::filesystem;
 
+#include <sys/wait.h>
+
 std::unordered_set<std::string> dependencies;
 const char *make_command = nullptr;
 
