diff --git src/lib/fcitx-utils/utils.c src/lib/fcitx-utils/utils.c
index c97ff44..473abc3 100644
--- src/lib/fcitx-utils/utils.c
+++ src/lib/fcitx-utils/utils.c
@@ -337,19 +337,23 @@ int fcitx_utils_pid_exists(pid_t pid)
     if (vm == 0) // ignore all error
         return 1;
 
-    int cnt;
-    struct kinfo_proc * kp = kvm_getprocs(vm, KERN_PROC_PID, pid, &cnt);
-    if (kp == 0)
-        return 1;
-    int i;
-    for (i = 0; i < cnt; i++)
-        if (kp->ki_pid == pid)
+    int result = 1;
+    do {
+        int cnt;
+        struct kinfo_proc * kp = kvm_getprocs(vm, KERN_PROC_PID, pid, &cnt);
+        if (kp == 0) {
+            result = 1;
             break;
-    int result;
-    if (i != cnt)
-        result = 1;
-    else
-        result = 0;
+        }
+        int i;
+        for (i = 0; i < cnt; i++)
+            if (kp->ki_pid == pid)
+                break;
+        if (i != cnt)
+            result = 1;
+        else
+            result = 0;
+    } while (0);
     kvm_close(vm);
     return result;
 #else
@@ -386,21 +390,24 @@ char* fcitx_utils_get_process_name()
     if (vm == 0)
         return strdup("");
 
-    int cnt;
-    int mypid = getpid();
-    struct kinfo_proc * kp = kvm_getprocs(vm, KERN_PROC_PID, mypid, &cnt);
-    if ((cnt != 1) || (kp == 0))
-        return strdup("");
-    int i;
-    for (i = 0; i < cnt; i++)
-        if (kp->ki_pid == mypid)
-            break;
     char* result = NULL;
-    if (i != cnt)
-        result = strdup(kp->ki_comm);
-    else
-        result = strdup("");
+    do {
+        int cnt;
+        int mypid = getpid();
+        struct kinfo_proc * kp = kvm_getprocs(vm, KERN_PROC_PID, mypid, &cnt);
+        if ((cnt != 1) || (kp == 0)) {
+            break;
+        }
+        int i;
+        for (i = 0; i < cnt; i++)
+            if (kp->ki_pid == mypid)
+                break;
+        if (i != cnt)
+            result = strdup(kp->ki_comm);
+    } while (0);
     kvm_close(vm);
+    if (result == NULL)
+        result = strdup("");
     return result;
 #else
     return strdup("");
