--- swoole_process.c.orig	2017-02-06 09:32:48 UTC
+++ swoole_process.c
@@ -963,7 +963,12 @@ static PHP_METHOD(swoole_process, setaff
         CPU_SET(Z_LVAL_P(value), &cpu_set);
     SW_HASHTABLE_FOREACH_END();
 
+#ifdef __FreeBSD__
+    if (cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID, -1,
+			    sizeof(cpu_set), &cpu_set) < 0)
+#else
     if (sched_setaffinity(getpid(), sizeof(cpu_set), &cpu_set) < 0)
+#endif
     {
         swoole_php_sys_error(E_WARNING, "sched_setaffinity() failed.");
         RETURN_FALSE;
