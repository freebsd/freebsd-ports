--- libs/fileplayer.cc.orig	2001-03-17 18:57:12 UTC
+++ libs/fileplayer.cc
@@ -10,7 +10,8 @@
 #endif
 
 #include <string.h>
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
