--- tests/bsdtestharness.c.orig	2021-09-17 04:54:52 UTC
+++ tests/bsdtestharness.c
@@ -20,6 +20,7 @@
 
 #include <dispatch/dispatch.h>
 #include <assert.h>
+#include <inttypes.h>
 #include <stdio.h>
 #include <stdlib.h>
 #if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
@@ -151,7 +152,7 @@ main(int argc, char *argv[])
 	//fprintf(stderr, "pid = %d\n", pid);
 	assert(pid > 0);
 
-#if defined(__linux__)
+#if defined(__unix__)
 	int status;
 	struct rusage usage;
 	struct timeval tv_stop, tv_wall;
@@ -166,9 +167,9 @@ main(int argc, char *argv[])
 
 	assert(res2 != -1);
 	test_long("Process exited", (WIFEXITED(status) && WEXITSTATUS(status) && WEXITSTATUS(status) != 0xff) || WIFSIGNALED(status), 0);
-	printf("[PERF]\twall time: %ld.%06ld\n", tv_wall.tv_sec, tv_wall.tv_usec);
-	printf("[PERF]\tuser time: %ld.%06ld\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
-	printf("[PERF]\tsystem time: %ld.%06ld\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
+	printf("[PERF]\twall time: %" PRIdMAX ".%06" PRIdMAX "\n", (intmax_t)tv_wall.tv_sec, (intmax_t)tv_wall.tv_usec);
+	printf("[PERF]\tuser time: %" PRIdMAX ".%06" PRIdMAX"\n", (intmax_t)usage.ru_utime.tv_sec, (intmax_t)usage.ru_utime.tv_usec);
+	printf("[PERF]\tsystem time: %" PRIdMAX ".%06" PRIdMAX "\n", (intmax_t)usage.ru_stime.tv_sec, (intmax_t)usage.ru_stime.tv_usec);
 	printf("[PERF]\tmax resident set size: %ld\n", usage.ru_maxrss);
 	printf("[PERF]\tpage faults: %ld\n", usage.ru_majflt);
 	printf("[PERF]\tswaps: %ld\n", usage.ru_nswap);
