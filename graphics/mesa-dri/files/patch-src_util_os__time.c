- Use monotonic clock for timeouts

--- src/util/os_time.c.orig	2018-04-21 05:48:25 UTC
+++ src/util/os_time.c
@@ -95,7 +95,7 @@ os_time_get_nano(void)
 void
 os_time_sleep(int64_t usecs)
 {
-#if defined(PIPE_OS_LINUX)
+#if defined(HAVE_CLOCK_NANOSLEEP)
    struct timespec time;
    time.tv_sec = usecs / 1000000;
    time.tv_nsec = (usecs % 1000000) * 1000;
