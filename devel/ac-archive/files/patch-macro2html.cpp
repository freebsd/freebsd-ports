--- macro2html.cpp.orig	Mon Aug 20 16:36:17 2001
+++ macro2html.cpp	Tue Nov  4 18:38:40 2003
@@ -16,6 +16,7 @@
 #include <vector>
 #include <memory>
 #include <cerrno>
+#include <sys/types.h>
 #include <regex.h>
 
 using namespace std;
