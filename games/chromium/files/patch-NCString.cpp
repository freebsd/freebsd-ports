--- src/NCString.cpp.orig	Fri Mar 14 19:57:50 2003
+++ src/NCString.cpp	Fri Mar 14 20:06:44 2003
@@ -5,6 +5,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <limits.h>
+#include <stdarg.h>
 
 /**
  * ctor
@@ -1055,7 +1056,7 @@
 uint NCString::toULong(const char *str, bool *ok)
 {
 	int n;
-	ulong tmp = 0;
+	unsigned long tmp = 0;
 	if(str)
 	{
 		n = sscanf(str, "%lu", &tmp);
