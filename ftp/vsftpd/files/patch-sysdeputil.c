--- sysdeputil.c.orig	2012-09-16 06:18:04.000000000 +0200
+++ sysdeputil.c	2012-10-13 20:20:42.000000000 +0200
@@ -57,7 +57,7 @@
 #endif
 #define VSF_SYSDEP_HAVE_SHADOW
 #define VSF_SYSDEP_HAVE_USERSHELL
-#define VSF_SYSDEP_HAVE_LIBCAP
+#undef VSF_SYSDEP_HAVE_LIBCAP
 #define VSF_SYSDEP_HAVE_UTMPX
 
 #define __USE_GNU
@@ -323,8 +323,12 @@
                       const struct mystr* p_remote_host)
 {
   int retval = -1;
+#ifdef PAM_USER
   pam_item_t item;
+#endif
+#ifdef PAM_RUSER
   const char* pam_user_name = 0;
+#endif
   struct pam_conv the_conv =
   {
     &pam_conv_func,
@@ -1216,7 +1220,9 @@
   setutxent();
   (void) pututxline(&s_utent);
   endutxent();
+#if !defined(__FreeBSD__)
   updwtmpx(WTMPX_FILE, &s_utent);
+#endif
 }
 
 void
@@ -1235,7 +1241,9 @@
   (void) pututxline(&s_utent);
   endutxent();
   s_utent.ut_tv.tv_sec = vsf_sysutil_get_time_sec();
+#if !defined(__FreeBSD__)
   updwtmpx(WTMPX_FILE, &s_utent);
+#endif
 }
 
 #endif /* !VSF_SYSDEP_HAVE_UTMPX */
