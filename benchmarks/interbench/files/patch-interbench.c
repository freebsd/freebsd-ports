--- interbench.c.orig	2009-10-31 04:14:59 UTC
+++ interbench.c
@@ -43,8 +43,12 @@
 #include <sys/time.h>
 #include <sys/resource.h>
 #include <sys/types.h>
+#include <sys/stat.h>
 #include <sys/mman.h>
 #include <sys/wait.h>
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#endif
 #include "interbench.h"
 
 #define MAX_UNAME_LENGTH	100
@@ -210,7 +214,7 @@ int test_fifo(void)
 {
 	struct sched_param sp;
 	memset(&sp, 0, sizeof(sp));
-	sp.sched_priority = 99;
+	sp.sched_priority = sched_get_priority_max(SCHED_FIFO);
 	if (sched_setscheduler(0, SCHED_FIFO, &sp) == -1) {
 		if (errno != EPERM)
 			terminal_error("sched_setscheduler");
@@ -888,7 +892,7 @@ void *timekeeping_thread(void *t)
 	 * accurate accounting remains SCHED_NORMAL;
 	 */
 	if (th->dt != &th->benchmarks[NOT_BENCHING])
-		set_fifo(96);
+		set_fifo(sched_get_priority_max(SCHED_FIFO) - 1);
 	/* These values must be changed at the appropriate places or race */
 	tk->sleep_interval = tk->slept_interval = 0;
 	post_sem(&s->ready);
@@ -1130,6 +1134,7 @@ write:
 
 void get_ram(void)
 {
+#if defined(__linux__)
 	FILE *meminfo;
         char aux[256];
  
@@ -1143,6 +1148,21 @@ void get_ram(void)
             fgets(aux,sizeof(aux),meminfo);
 	if (fclose(meminfo) == -1)
 		terminal_error("fclose");
+#elif defined(__FreeBSD__)
+	long pagesize, numpages;
+	quad_t swap;
+	size_t len = sizeof(swap);
+
+	pagesize = sysconf(_SC_PAGESIZE);
+	numpages = sysconf(_SC_PHYS_PAGES);
+	if (sysctlbyname("vm.swap_total", &swap, &len, NULL, 0) == -1)
+		swap = 0;
+
+	ud.ram = pagesize / 1024 * numpages;
+	ud.swap = swap / 1024;
+#else
+#error unsupported operating system
+#endif
 
 	if( !ud.ram || !ud.swap ) {
 		unsigned long i;
@@ -1293,7 +1313,8 @@ void run_benchchild(int i, int j)
 	thi->dt = &thi->benchmarks[j];
 	initialise_thread_data(thi->dt);
 	if (ud.do_rt)
-		set_thread_fifo(thi->pthread, 95);
+		set_thread_fifo(thi->pthread,
+		    sched_get_priority_max(SCHED_FIFO) - 1);
 	
 	/* Tell main we're ready */
 	wakeup_with(b2m[1]);
@@ -1344,7 +1365,7 @@ void bench(int i, int j)
 	 * We want to be higher priority than everything to signal them to
 	 * stop and we lock our memory if we can as well
 	 */
-	set_fifo(99);
+	set_fifo(sched_get_priority_max(SCHED_FIFO));
 	set_mlock();
 
 	/* Wakeup the load process */
@@ -1652,7 +1673,7 @@ bench:
 		 * To get as accurate a loop as possible we time it running
 		 * SCHED_FIFO if we can
 		 */
-		set_fifo(99);
+		set_fifo(sched_get_priority_max(SCHED_FIFO));
 		calibrate_loop();
 		set_normal();
 	} else
