--- src/jdk.management/unix/native/libmanagement_ext/OperatingSystemImpl.c.orig	2025-04-19 23:57:10 UTC
+++ src/jdk.management/unix/native/libmanagement_ext/OperatingSystemImpl.c
@@ -58,6 +58,7 @@
 #include <unistd.h>
 
 #ifdef __FreeBSD__
+#include <sys/user.h>
 #include <vm/vm_param.h>
 #endif
 
@@ -261,23 +262,43 @@ Java_com_sun_management_internal_OperatingSystemImpl_g
     }
     return t_info.virtual_size;
 #elif defined(__FreeBSD__)
-    FILE *fp;
-    unsigned long end, start;
-    jlong total = 0;
+    int mib[4];
+    struct kinfo_vmentry *kve;
+    long total = 0;
+    size_t len = 0;
+    int error;
+    char *buf, *bp, *eb;
 
-    if ((fp = fopen("/proc/curproc/map", "r")) == NULL) {
-        throw_internal_error(env, "Unable to open /proc/curproc/map");
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC;
+    mib[2] = KERN_PROC_VMMAP;
+    mib[3] = getpid();
+    error = sysctl(mib, 4, NULL, &len, NULL, 0);
+    if (error) {
+        throw_internal_error(env, "Cannot sysctl(kern.proc.vvmap)");
         return -1;
     }
-
-    for (;;) {
-       // Ignore everything except start and end entries
-       if (fscanf(fp, "0x%lx 0x%lx %*[^\n]\n", &start, &end) != 2 || start > end)
-           break;
-       total += end - start;
+    len = len * 4 / 3;
+    buf = malloc(len);
+    if (buf == NULL) {
+        throw_internal_error(env, "Fail to allocate memory");
+        return -1;
     }
-
-    fclose(fp);
+    error = sysctl(mib, 4, buf, &len, NULL, 0);
+    if (error) {
+        throw_internal_error(env, "Cannot sysctl(kern.proc.vvmap)");
+        return -1;
+    }
+    bp = buf;
+    eb = buf + len;
+    while (bp < eb) {
+        kve = (struct kinfo_vmentry *)(uintptr_t)bp;
+        if (kve->kve_structsize == 0)
+            break;
+        bp += kve->kve_structsize;
+        total += kve->kve_end - kve->kve_start;
+    }
+    free(buf);
     return total;
 #else /* _ALLBSD_SOURCE */
     /*
@@ -487,6 +508,21 @@ Java_com_sun_management_internal_OperatingSystemImpl_g
     return nfiles;
 #elif defined(__OpenBSD__)
     return getdtablecount();
+#elif defined(__FreeBSD__)
+    int mib[4];
+    int error;
+    int nfds;
+    size_t len;
+
+    len = sizeof(nfds);
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC;
+    mib[2] = KERN_PROC_NFDS;
+    mib[3] = 0;
+
+    if (sysctl(mib, 4, &nfds, &len, NULL, 0) == -1)
+        return -1;
+    return nfds;
 #else /* solaris/linux */
     DIR *dirp;
     struct dirent64* dentp;
