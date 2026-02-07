--- src/Input/fgjs.cxx.orig	2020-05-28 21:56:43 UTC
+++ src/Input/fgjs.cxx
@@ -38,6 +38,8 @@
 #include <fstream>
 #include <string>
 
+#include <unistd.h>
+
 using std::fstream;
 using std::cout;
 using std::cin;
