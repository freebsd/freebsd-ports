--- src/sp.cpp.orig	2005-05-08 20:11:29.000000000 +0400
+++ src/sp.cpp	2014-07-23 03:21:49.000000000 +0400
@@ -11,6 +11,7 @@
 #include <sys/stat.h>
 #include <limits.h>
 #include <ctype.h>
+#include <unistd.h> // for access()
 
 #include "main.h"
 #include "sp.h"
