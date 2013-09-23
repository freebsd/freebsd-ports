--- libs/fileplayer.cc.orig	2001-03-17 19:57:12.000000000 +0100
+++ libs/fileplayer.cc	2013-09-23 12:12:55.000000000 +0200
@@ -10,7 +10,8 @@
 #endif
 
 #include <string.h>
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
