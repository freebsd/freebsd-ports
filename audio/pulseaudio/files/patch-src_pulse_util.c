--- src/pulse/util.c.orig	2015-02-12 15:10:35.000000000 +0100
+++ src/pulse/util.c	2015-05-31 17:50:08.221242000 +0200
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
@@ -215,13 +219,14 @@ char *pa_get_binary_name(char *s, size_t
 
 #ifdef __FreeBSD__
     {
-        char *rp;
-
-        if ((rp = pa_readlink("/proc/curproc/file"))) {
-            pa_strlcpy(s, pa_path_get_filename(rp), l);
-            pa_xfree(rp);
-            return s;
-        }
+        int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, getpid()};
+        struct kinfo_proc kp;
+        size_t sz = sizeof(kp);
+
+	if (sysctl(mib, 4, &kp, &sz, NULL, 0) == 0)
+          return kp.ki_comm;
+        else
+          return NULL;
     }
 #endif
 
