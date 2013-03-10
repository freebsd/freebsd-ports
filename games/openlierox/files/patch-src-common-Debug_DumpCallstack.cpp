--- src/common/Debug_DumpCallstack.cpp.orig	2012-04-17 04:26:14.000000000 +0400
+++ src/common/Debug_DumpCallstack.cpp	2012-12-14 23:19:15.525963503 +0400
@@ -11,6 +11,8 @@
 #include "util/macros.h"
 #include <vector>
 #include <string>
+#include <cstdio>
+#include <cstdlib>
 
 #ifndef HAVE_EXECINFO
 #	if defined(__linux__)
@@ -25,8 +27,6 @@
 #if HAVE_EXECINFO
 
 #include <execinfo.h>
-#include <stdio.h>
-#include <stdlib.h>
 
 #if HASBFD
 
