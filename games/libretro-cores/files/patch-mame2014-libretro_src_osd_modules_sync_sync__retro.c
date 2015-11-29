--- mame2014-libretro/src/osd/modules/sync/sync_retro.c.orig	2015-11-04 17:31:20 UTC
+++ mame2014-libretro/src/osd/modules/sync/sync_retro.c
@@ -42,6 +42,8 @@
 #include <signal.h>
 #include <sys/time.h>
 
+#include <pthread_np.h>
+
 #ifndef WIN32
 struct hidden_mutex_t {
 	pthread_mutex_t id;
@@ -492,7 +494,7 @@ int osd_thread_cpu_affinity(osd_thread *
 #if defined(__GNUC__) && defined(WIN32)
    return TRUE; /* stub */
 #elif !defined(NO_AFFINITY_NP) && !defined(__MACH__) && !defined(SDLMAME_ARM)
-	cpu_set_t   cmask;
+	cpuset_t   cmask;
 	pthread_t   lthread;
 	int         bitnum;
 
