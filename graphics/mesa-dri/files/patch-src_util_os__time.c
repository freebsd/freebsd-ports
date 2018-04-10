- Use monotonic clock for timeouts

--- src/util/os_time.c.orig	2018-01-23 18:08:50 UTC
+++ src/util/os_time.c
@@ -55,7 +55,7 @@
 int64_t
 os_time_get_nano(void)
 {
-#if defined(PIPE_OS_LINUX)
+#if defined(PIPE_OS_BSD) || defined(PIPE_OS_LINUX)
 
    struct timespec tv;
    clock_gettime(CLOCK_MONOTONIC, &tv);
@@ -95,7 +95,7 @@ os_time_get_nano(void)
 void
 os_time_sleep(int64_t usecs)
 {
-#if defined(PIPE_OS_LINUX)
+#if defined(HAVE_CLOCK_NANOSLEEP)
    struct timespec time;
    time.tv_sec = usecs / 1000000;
    time.tv_nsec = (usecs % 1000000) * 1000;
