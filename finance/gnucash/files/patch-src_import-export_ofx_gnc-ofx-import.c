--- src/import-export/ofx/gnc-ofx-import.c.orig	2016-12-15 21:46:51 UTC
+++ src/import-export/ofx/gnc-ofx-import.c
@@ -336,8 +336,25 @@ fix_ofx_bug_39 (time64 t)
 {
 #if HAVE_OFX_BUG_39
     struct tm stm;
+
+#ifdef __FreeBSD__
+    time64 now;
+    /*
+     * FreeBSD has it's own libc implementation which differs from glibc. In particular:
+     * There is no daylight global
+     * tzname members are set to the string "   " (three spaces) when not explicitly populated
+     *
+     * To check that the current timezone does not observe DST I check if tzname[1] starts with a space.
+     */
+    now = gnc_time (NULL);
+    gnc_localtime_r(&now, &stm);
+    tzset();
+
+    if (tzname[1][0] != ' ' && !stm.tm_isdst)
+#else
     gnc_localtime_r(&t, &stm);
     if (daylight && !stm.tm_isdst)
+#endif
       t += 3600;
 #endif
     return t;
