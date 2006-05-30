--- src/cpu/core_dyn_x86.cpp.orig      Thu Feb  9 12:32:52 2006
+++ src/cpu/core_dyn_x86.cpp   Thu May 25 22:58:53 2006
@@ -22,6 +22,8 @@

 #define CHECKED_MEMORY_ACCESS

+#include <sys/types.h>
+
 #include <assert.h>
 #include <stdarg.h>
 #include <stdio.h>
