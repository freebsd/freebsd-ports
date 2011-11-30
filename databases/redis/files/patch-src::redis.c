--- src/redis.c.orig	2011-11-30 16:29:38.000000000 +0400
+++ src/redis.c	2011-11-30 16:29:59.000000000 +0400
@@ -1685,7 +1685,7 @@
 #ifdef HAVE_BACKTRACE
 static void *getMcontextEip(ucontext_t *uc) {
 #if defined(__FreeBSD__)
-    return (void*) uc->uc_mcontext.mc_eip;
+    return (void*) uc->uc_mcontext.mc_rip;
 #elif defined(__dietlibc__)
     return (void*) uc->uc_mcontext.eip;
 #elif defined(__APPLE__) && !defined(MAC_OS_X_VERSION_10_6)
