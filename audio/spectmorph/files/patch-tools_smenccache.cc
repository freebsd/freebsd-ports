--- tools/smenccache.cc.orig	2021-06-27 09:40:09 UTC
+++ tools/smenccache.cc
@@ -4,6 +4,7 @@
 #include "smutils.hh"
 #include <string>
 #include <vector>
+#include <sys/wait.h> // for WEXITSTATUS
 
 using std::string;
 using std::vector;
