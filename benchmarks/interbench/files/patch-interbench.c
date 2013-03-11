--- interbench.c.orig	2009-10-31 12:14:59.000000000 +0800
+++ interbench.c	2013-03-11 20:56:50.000000000 +0800
@@ -43,6 +43,7 @@
 #include <sys/time.h>
 #include <sys/resource.h>
 #include <sys/types.h>
+#include <sys/stat.h>
 #include <sys/mman.h>
 #include <sys/wait.h>
 #include "interbench.h"
@@ -210,7 +211,7 @@ int test_fifo(void)
 {
 	struct sched_param sp;
 	memset(&sp, 0, sizeof(sp));
-	sp.sched_priority = 99;
+	sp.sched_priority = sched_get_priority_max(SCHED_FIFO);
 	if (sched_setscheduler(0, SCHED_FIFO, &sp) == -1) {
 		if (errno != EPERM)
 			terminal_error("sched_setscheduler");
@@ -888,7 +889,7 @@ void *timekeeping_thread(void *t)
 	 * accurate accounting remains SCHED_NORMAL;
 	 */
 	if (th->dt != &th->benchmarks[NOT_BENCHING])
-		set_fifo(96);
+		set_fifo(sched_get_priority_max(SCHED_FIFO) - 1);
 	/* These values must be changed at the appropriate places or race */
 	tk->sleep_interval = tk->slept_interval = 0;
 	post_sem(&s->ready);
@@ -1133,7 +1134,7 @@ void get_ram(void)
 	FILE *meminfo;
         char aux[256];
  
-	if(!(meminfo = fopen("/proc/meminfo", "r")))
+	if(!(meminfo = fopen("/compat/linux/proc/meminfo", "r")))
 		terminal_error("fopen");
 
 	ud.ram = ud.swap = 0;
@@ -1293,7 +1294,8 @@ void run_benchchild(int i, int j)
 	thi->dt = &thi->benchmarks[j];
 	initialise_thread_data(thi->dt);
 	if (ud.do_rt)
-		set_thread_fifo(thi->pthread, 95);
+		set_thread_fifo(thi->pthread,
+		    sched_get_priority_max(SCHED_FIFO) - 1);
 	
 	/* Tell main we're ready */
 	wakeup_with(b2m[1]);
@@ -1344,7 +1346,7 @@ void bench(int i, int j)
 	 * We want to be higher priority than everything to signal them to
 	 * stop and we lock our memory if we can as well
 	 */
-	set_fifo(99);
+	set_fifo(sched_get_priority_max(SCHED_FIFO));
 	set_mlock();
 
 	/* Wakeup the load process */
@@ -1652,7 +1654,7 @@ bench:
 		 * To get as accurate a loop as possible we time it running
 		 * SCHED_FIFO if we can
 		 */
-		set_fifo(99);
+		set_fifo(sched_get_priority_max(SCHED_FIFO));
 		calibrate_loop();
 		set_normal();
 	} else
