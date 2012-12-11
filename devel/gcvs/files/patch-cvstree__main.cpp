--- cvstree/main.cpp.orig	2002-07-10 22:43:47.000000000 +0900
+++ cvstree/main.cpp	2012-11-06 16:21:19.000000000 +0900
@@ -1,6 +1,7 @@
-#include <stdio.h>
+#include <cstdio>
 #include "getopt.h"
-#include <errno.h>
+#include <cerrno>
+#include <cstdlib>
 using namespace std;
 
 #if defined(_MSC_VER) && _MSC_VER < 0x514 && __GNUC__<3  // VC7  and gcc 3
