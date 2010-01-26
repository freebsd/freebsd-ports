--- sysdeputil.c.orig	2009-11-12 04:16:15.000000000 +0100
+++ sysdeputil.c	2010-01-26 22:30:10.000000000 +0100
@@ -1213,7 +1213,9 @@
   setutxent();
   (void) pututxline(&s_utent);
   endutxent();
+#if !defined(__FreeBSD__)
   updwtmpx(WTMPX_FILE, &s_utent);
+#endif
 }
 
 void
@@ -1232,7 +1234,9 @@
   (void) pututxline(&s_utent);
   endutxent();
   s_utent.ut_tv.tv_sec = vsf_sysutil_get_time_sec();
+#if !defined(__FreeBSD__)
   updwtmpx(WTMPX_FILE, &s_utent);
+#endif
 }
 
 #endif /* !VSF_SYSDEP_HAVE_UTMPX */
