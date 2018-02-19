--- Alc/helpers.c.orig 2018-02-19 01:00:00 UTC
+++ Alc/helpers.c
@@ -735,7 +735,7 @@ void GetProcBinary(al_string *path, al_string *fname)
     size_t pathlen;
 
 #ifdef __FreeBSD__
-    int mib[4] = { CTL_KERN, KERN_PROCARGS, getpid() };
+    int mib[4] = { CTL_KERN, KERN_PROC_ARGS, getpid() };
     if(sysctl(mib, 3, NULL, &pathlen, NULL, 0) == -1)
         WARN("Failed to sysctl kern.procargs.%d: %s\n", mib[2], strerror(errno));
     else
