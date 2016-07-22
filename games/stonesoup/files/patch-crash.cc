--- crash.cc.orig	2016-06-28 19:06:21 UTC
+++ crash.cc
@@ -270,14 +270,6 @@ void init_crash_handler()
 
 void dump_crash_info(FILE* file)
 {
-#if defined(UNIX)
-    const char *name = strsignal(_crash_signal);
-    if (name == nullptr)
-        name = "INVALID";
-
-    fprintf(file, "Crash caused by signal #%d: %s\n\n", _crash_signal,
-            name);
-#endif
 }
 
 #if defined(BACKTRACE_SUPPORTED)
