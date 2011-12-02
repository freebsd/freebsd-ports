--- src/redis.c.orig	2011-11-28 14:22:08.000000000 +0400
+++ src/redis.c	2011-12-02 06:23:15.000000000 +0400
@@ -1685,7 +1685,11 @@
 #ifdef HAVE_BACKTRACE
 static void *getMcontextEip(ucontext_t *uc) {
 #if defined(__FreeBSD__)
-    return (void*) uc->uc_mcontext.mc_eip;
+  #if __x86_64__
+    return (void*) uc->uc_mcontext.mc_rip;
+  #elif __i386__
+    return (void*) uc->uc_mcontext.mc_eip;
+  #endif
 #elif defined(__dietlibc__)
     return (void*) uc->uc_mcontext.eip;
 #elif defined(__APPLE__) && !defined(MAC_OS_X_VERSION_10_6)
