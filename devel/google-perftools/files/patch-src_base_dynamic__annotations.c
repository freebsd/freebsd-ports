- add another way to determine if the process is run under valgrind - based on LD_PRELOAD patterns presence
- Submitted: https://github.com/gperftools/gperftools/pull/1316

--- src/base/dynamic_annotations.c.orig	2021-02-15 06:44:21 UTC
+++ src/base/dynamic_annotations.c
@@ -43,6 +43,19 @@
 #include "base/dynamic_annotations.h"
 #include "getenv_safe.h" // for TCMallocGetenvSafe
 
+static int running_on_valgrind_preload = -1;
+void __attribute__ ((constructor)) premain() {
+  char *LD_PRELOAD = getenv("LD_PRELOAD");
+  running_on_valgrind_preload = LD_PRELOAD != NULL &&
+    (
+      strstr(LD_PRELOAD, "/valgrind/") != NULL
+      ||
+      strstr(LD_PRELOAD, "/vgpreload") != NULL
+    )
+    ?
+    1 : 0;
+}
+
 static int GetRunningOnValgrind(void) {
 #ifdef RUNNING_ON_VALGRIND
   if (RUNNING_ON_VALGRIND) return 1;
@@ -51,6 +64,11 @@ static int GetRunningOnValgrind(void) {
   if (running_on_valgrind_str) {
     return strcmp(running_on_valgrind_str, "0") != 0;
   }
+
+  // use the LD_PRELOAD trick from https://stackoverflow.com/questions/365458/how-can-i-detect-if-a-program-is-running-from-within-valgrind
+  if (running_on_valgrind_preload == 1)
+    return 1;
+
   return 0;
 }
 
