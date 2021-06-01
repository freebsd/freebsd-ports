--- pkg/proc/native/proc_freebsd.h.orig	2021-05-19 07:24:05 UTC
+++ pkg/proc/native/proc_freebsd.h
@@ -1,4 +1,6 @@
+#include <sys/types.h>
+
 char * find_command_name(int pid);
 char * find_executable(int pid);
 int find_status(int pid);
-int get_entry_point(int pid);
+uintptr_t get_entry_point(int pid);
