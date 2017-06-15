--- src/import-export/ofx/gnc-ofx-import.c.orig	2016-12-15 21:46:51 UTC
+++ src/import-export/ofx/gnc-ofx-import.c
@@ -337,7 +337,11 @@ fix_ofx_bug_39 (time64 t)
 #if HAVE_OFX_BUG_39
     struct tm stm;
     gnc_localtime_r(&t, &stm);
+#ifdef __FreeBSD__
+    if (!stm.tm_isdst)
+#else
     if (daylight && !stm.tm_isdst)
+#endif
       t += 3600;
 #endif
     return t;
