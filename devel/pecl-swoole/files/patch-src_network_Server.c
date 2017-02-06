--- src/network/Server.c.orig	2017-02-06 09:30:50 UTC
+++ src/network/Server.c
@@ -522,7 +522,13 @@ int swServer_worker_init(swServer *serv,
         {
             CPU_SET(SwooleWG.id % SW_CPU_NUM, &cpu_set);
         }
+
+#ifdef __FreeBSD__
+	if (cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID, -1,
+				sizeof(cpu_set), &cpu_set) < 0)
+#else
         if (sched_setaffinity(getpid(), sizeof(cpu_set), &cpu_set) < 0)
+#endif
         {
             swSysError("sched_setaffinity() failed.");
         }
