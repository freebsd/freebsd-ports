--- src/pulse/util.c.orig	2015-12-29 00:56:00 UTC
+++ src/pulse/util.c
@@ -30,6 +30,10 @@
 #include <time.h>
 #include <unistd.h>
 #include <sys/types.h>
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#endif
 
 #ifdef HAVE_PWD_H
 #include <pwd.h>
@@ -200,7 +204,7 @@ char *pa_get_binary_name(char *s, size_t
     }
 #endif
 
-#if defined(__linux__) || defined(__FreeBSD_kernel__)
+#if defined(__linux__) || (defined(__FreeBSD_kernel__) && !defined(__FreeBSD__))
     {
         char *rp;
         /* This works on Linux and Debian/kFreeBSD */
@@ -215,13 +219,17 @@ char *pa_get_binary_name(char *s, size_t
 
 #ifdef __FreeBSD__
     {
-        char *rp;
+        int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, getpid()};
+        struct kinfo_proc kp;
+        size_t sz = sizeof(kp);
 
-        if ((rp = pa_readlink("/proc/curproc/file"))) {
-            pa_strlcpy(s, pa_path_get_filename(rp), l);
-            pa_xfree(rp);
-            return s;
+        if (sysctl(mib, 4, &kp, &sz, NULL, 0) == 0)
+        {
+          pa_strlcpy(s, kp.ki_comm, l);
+          return kp.ki_comm;
         }
+        else
+          return NULL;
     }
 #endif
 
