--- src/core/filewatch.c.orig	2026-08-31 23:24:25 UTC
+++ src/core/filewatch.c
@@ -29,7 +29,15 @@
 #ifdef JANET_EV
 #ifdef JANET_FILEWATCH
 
-#ifdef JANET_LINUX
+#if defined(JANET_APPLE) || defined(JANET_BSD)
+#define JANET_KQUEUE 1
+#endif
+#if defined(JANET_LINUX) %INOTIFY%
+#undef  JANET_KQUEUE
+#define JANET_INOTIFY 1
+#endif
+
+#ifdef JANET_INOTIFY
 #include <sys/inotify.h>
 #include <unistd.h>
 #endif
@@ -38,7 +46,7 @@
 #include <windows.h>
 #endif
 
-#if defined(JANET_APPLE) || defined(JANET_BSD)
+#ifdef JANET_KQUEUE
 #include <sys/event.h>
 #include <sys/stat.h>
 #include <unistd.h>
@@ -60,7 +68,7 @@ typedef struct {
     int is_watching;
 } JanetWatcher;
 
-#ifdef JANET_LINUX
+#ifdef JANET_INOTIFY
 
 #include <sys/inotify.h>
 #include <unistd.h>
@@ -96,7 +104,7 @@ static uint32_t decode_watch_flags(const Janet *option
             sizeof(JanetWatchFlagName),
             keyw);
         if (!result) {
-            janet_panicf("unknown linux flag %v", options[i]);
+            janet_panicf("unknown inotify flag %v", options[i]);
         }
         flags |= result->flag;
     }
@@ -122,7 +130,8 @@ static void janet_watcher_add(JanetWatcher *watcher, c
     if (watcher->stream == NULL) janet_panic("watcher closed");
     int result;
     do {
-        result = inotify_add_watch(watcher->stream->handle, path, flags);
+        /* FreeBSD is not forgiving about returned-only flags, just make sure off */
+        result = inotify_add_watch(watcher->stream->handle, path, flags & ~(IN_IGNORED|IN_ISDIR|IN_Q_OVERFLOW|IN_UNMOUNT));
     } while (result == -1 && errno == EINTR);
     if (result == -1) {
         janet_panicv(janet_ev_lasterr());
@@ -514,7 +523,7 @@ static void janet_watcher_unlisten(JanetWatcher *watch
     janet_gcunroot(janet_wrap_abstract(watcher));
 }
 
-#elif defined(JANET_APPLE) || defined(JANET_BSD)
+#elif JANET_KQUEUE
 
 /* kqueue implementation */
 
