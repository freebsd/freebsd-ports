--- external/dmon/dmon.h.orig	2024-04-03 12:42:33 UTC
+++ external/dmon/dmon.h
@@ -137,7 +137,7 @@ DMON_API_DECL void dmon_unwatch(dmon_watch_id id);
 #if defined(_WIN32) || defined(_WIN64)
 #    undef DMON_OS_WINDOWS
 #    define DMON_OS_WINDOWS 1
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #    undef DMON_OS_LINUX
 #    define DMON_OS_LINUX 1
 #elif defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__)
@@ -167,7 +167,7 @@ DMON_API_DECL void dmon_unwatch(dmon_watch_id id);
 #    include <dirent.h>
 #    include <errno.h>
 #    include <fcntl.h>
-#    include <linux/limits.h>
+//#    include <linux/limits.h>
 #    include <pthread.h>
 #    include <sys/inotify.h>
 #    include <sys/stat.h>
