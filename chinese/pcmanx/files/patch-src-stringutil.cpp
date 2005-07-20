--- src/stringutil.cpp.orig	Thu Jul  7 14:08:01 2005
+++ src/stringutil.cpp	Wed Jul 20 13:32:46 2005
@@ -11,6 +11,7 @@
 
 #include "stringutil.h"
 #include <ctype.h>
+#include <stdio.h>
 
 int strncmpi(const char* str1, const char* str2, size_t len)
 {
