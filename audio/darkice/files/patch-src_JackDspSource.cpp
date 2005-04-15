--- src/JackDspSource.cpp.orig Mon Apr  4 17:36:17 2005
+++ src/JackDspSource.cpp      Fri Apr 15 04:15:23 2005
@@ -38,6 +38,18 @@
 #include "config.h"
 #endif
 
+#ifdef HAVE_STDIO_H
+#include <stdio.h>
+#else
+#error need stdio.h
+#endif
+
+#ifdef HAVE_STDLIB_H
+#include <stdlib.h>
+#else
+#error need stdlib.h
+#endif
+
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #else
@@ -60,6 +72,10 @@
 #include <math.h>
 #else
 #error need math.h
+#endif
+
+#ifdef __FreeBSD__
+#define lrintf(x) rintf(x)
 #endif
 
 #include "Util.h"
