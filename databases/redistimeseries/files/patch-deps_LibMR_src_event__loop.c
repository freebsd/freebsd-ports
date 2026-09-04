--- deps/LibMR/src/event_loop.c.orig	2025-04-15 11:24:04 UTC
+++ deps/LibMR/src/event_loop.c
@@ -13,6 +13,8 @@

 #if defined(__linux__)
 #include <sys/prctl.h>
+#elif defined(__FreeBSD__)
+#include <pthread_np.h>
 #endif

 struct {
@@ -98,6 +100,8 @@ static void* MR_Loop(void *arg) {
   prctl(PR_SET_NAME, xstr(MODULE_NAME)"-el");
 #elif defined(__APPLE__) && defined(__MACH__)
   pthread_setname_np(xstr(MODULE_NAME)"-el");
+#elif defined(__FreeBSD__)
+  pthread_set_name_np(pthread_self(), xstr(MODULE_NAME)"-el");
 #else
   err("thread_do(): pthread_setname_np is not supported on this system");
 #endif
