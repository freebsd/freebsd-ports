--- regutil/regini.c.orig	2019-10-06 06:19:40 UTC
+++ regutil/regini.c
@@ -26,6 +26,7 @@
 #endif
 
 #include "regutil.h"
+#include </usr/include/strings.h>
 
 #ifdef _WIN32
 # include <windows.h>
@@ -547,10 +548,10 @@ rxfunc(sysqueryprocess)
       result->strlength = 6;
    }
    else if (!strcmp(arg, "PTIME")) {
-      result->strlength = sprintf(result->strptr, "%lu", clock());
+      result->strlength = sprintf(result->strptr, "%u", clock());
    }
    else if (!strcmp(arg, "TTIME")) {
-      result->strlength = sprintf(result->strptr, "%lu", clock());
+      result->strlength = sprintf(result->strptr, "%u", clock());
    }
    else
       return BADARGS;
