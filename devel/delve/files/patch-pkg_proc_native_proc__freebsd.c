--- pkg/proc/native/proc_freebsd.c.orig	2021-05-19 07:24:05 UTC
+++ pkg/proc/native/proc_freebsd.c
@@ -3,11 +3,13 @@
 #include <sys/queue.h>
 #include <sys/sysctl.h>
 #include <sys/user.h>
+#include <sys/types.h>
 
 #include <libprocstat.h>
 #include <libutil.h>
 #include <stdlib.h>
 #include <string.h>
+#include <errno.h>
 
 #include "proc_freebsd.h"
 
@@ -66,21 +68,23 @@ int find_status(int pid){
 	return (status);
 }
 
-int get_entry_point(int pid) {
+uintptr_t get_entry_point(int pid) {
     void *ep = NULL;
 
+    errno = EINVAL;
+
     struct procstat *ps = procstat_open_sysctl();
     if (ps == NULL)
-        return -1;
+        return 0;
 
     uint cnt = 0;
     struct kinfo_proc *kipp = procstat_getprocs(ps, KERN_PROC_PID, pid, &cnt);
     if (cnt == 0)
-        return -1;
+        return 0;
 
     Elf_Auxinfo *auxv = procstat_getauxv(ps, kipp, &cnt);
     if (auxv == NULL)
-        return -1;
+        return 0;
 
     for (int i = 0; i < cnt; i++) {
         if (auxv[i].a_type == AT_ENTRY) {
@@ -89,5 +93,6 @@ int get_entry_point(int pid) {
         }
     }
     procstat_freeauxv(ps, auxv);
-    return (int)ep;
+    errno = 0;
+    return (uintptr_t)ep;
 }
