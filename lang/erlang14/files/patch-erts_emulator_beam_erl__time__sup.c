
$FreeBSD$

--- erts/emulator/beam/erl_time_sup.c.orig
+++ erts/emulator/beam/erl_time_sup.c
@@ -648,6 +648,9 @@
     t.tm_sec = *second;
     t.tm_isdst = isdst;
     the_clock = mktime(&t);
+    if (the_clock == -1) {
+      return 0;
+    }
 #ifdef HAVE_GMTIME_R
     gmtime_r(&the_clock, (tm = &tmbuf));
 #else
