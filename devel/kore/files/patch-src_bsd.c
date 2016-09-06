Needed for building on FreeBSD 9.x.  Once FreeBSD 9 support ends this
patch can be removed.

cc1: warnings being treated as errors
src/bsd.c: In function 'kore_platform_worker_setcpu':
src/bsd.c:65: warning: declaration of 'cpuset' shadows a global declaration
/usr/include/sys/cpuset.h:131: warning: shadowed declaration is here

--- src/bsd.c.orig	2016-08-01 07:59:32 UTC
+++ src/bsd.c
@@ -62,12 +62,12 @@ void
 kore_platform_worker_setcpu(struct kore_worker *kw)
 {
 #if defined(__FreeBSD_version)
-	cpuset_t	cpuset;
+	cpuset_t	cpuset1;
 
-	CPU_ZERO(&cpuset);
-	CPU_SET(kw->cpu, &cpuset);
+	CPU_ZERO(&cpuset1);
+	CPU_SET(kw->cpu, &cpuset1);
 	if (cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID,
-	    -1, sizeof(cpuset), &cpuset) == -1) {
+	    -1, sizeof(cpuset1), &cpuset1) == -1) {
 		fatal("failed: %s", errno_s);
 	}
 
