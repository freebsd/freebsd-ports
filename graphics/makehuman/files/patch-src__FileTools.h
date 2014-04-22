--- src/FileTools.h.orig	2007-11-25 12:28:06.000000000 +0300
+++ src/FileTools.h	2014-03-29 06:24:08.329334425 +0400
@@ -35,6 +35,9 @@
 #include <string>
 #include <list>
 #include <cassert>
+#include <stdint.h>
+#include <fcntl.h>
+#include <unistd.h>
 
 using std::string;
 using std::list;
