--- lib/Support/Unix/Path.inc.orig	2020-10-19 17:56:15 UTC
+++ lib/Support/Unix/Path.inc
@@ -208,14 +208,9 @@ std::string getMainExecutable(const char *argv0, void 
   while (*p++ != 0)
     ;
   // Iterate through auxiliary vectors for AT_EXECPATH.
-  for (;;) {
-    switch (*(uintptr_t *)p++) {
-    case AT_EXECPATH:
+  for (; (uintptr_t *)p != AT_NULL; p++) {
+    if (*(uintptr_t *)p++ == AT_EXECPATH)
       return *p;
-    case AT_NULL:
-      break;
-    }
-    p++;
   }
 #endif
   // Fall back to argv[0] if auxiliary vectors are not available.
