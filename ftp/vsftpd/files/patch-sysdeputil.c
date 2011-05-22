--- sysdeputil.c.orig	2010-03-26 06:25:33.000000000 +0300
+++ sysdeputil.c	2011-05-17 20:51:35.350022421 +0400
@@ -57,7 +57,7 @@
 #endif
 #define VSF_SYSDEP_HAVE_SHADOW
 #define VSF_SYSDEP_HAVE_USERSHELL
-#define VSF_SYSDEP_HAVE_LIBCAP
+#undef VSF_SYSDEP_HAVE_LIBCAP
 #define VSF_SYSDEP_HAVE_UTMPX
 
 #define __USE_GNU
@@ -1213,7 +1213,9 @@ vsf_insert_uwtmp(const struct mystr* p_u
   setutxent();
   (void) pututxline(&s_utent);
   endutxent();
+#if !defined(__FreeBSD__)
   updwtmpx(WTMPX_FILE, &s_utent);
+#endif
 }
 
 void
@@ -1232,7 +1234,9 @@ vsf_remove_uwtmp(void)
   (void) pututxline(&s_utent);
   endutxent();
   s_utent.ut_tv.tv_sec = vsf_sysutil_get_time_sec();
+#if !defined(__FreeBSD__)
   updwtmpx(WTMPX_FILE, &s_utent);
+#endif
 }
 
 #endif /* !VSF_SYSDEP_HAVE_UTMPX */
