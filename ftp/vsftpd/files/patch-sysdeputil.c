--- sysdeputil.c.orig	2012-09-16 04:18:04 UTC
+++ sysdeputil.c
@@ -103,6 +103,7 @@
 #if (defined(__FreeBSD__) && __FreeBSD__ >= 3)
   #define VSF_SYSDEP_HAVE_FREEBSD_SENDFILE
   #define VSF_SYSDEP_HAVE_SETPROCTITLE
+  #undef VSF_SYSDEP_HAVE_LIBCAP
 #endif
 
 #if defined(__NetBSD__)
@@ -177,8 +178,10 @@
 #include <crypt.h>
 #endif
 
+#ifdef VSF_SYSDEP_HAVE_LIBCAP
 /* Prefer libcap based capabilities over raw syscall capabilities */
 #include <sys/capability.h>
+#endif
 
 #if defined(VSF_SYSDEP_HAVE_CAPABILITIES) && !defined(VSF_SYSDEP_HAVE_LIBCAP)
 #include <linux/unistd.h>
@@ -323,8 +326,12 @@ vsf_sysdep_check_auth(struct mystr* p_us
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
@@ -1216,7 +1223,9 @@ vsf_insert_uwtmp(const struct mystr* p_u
   setutxent();
   (void) pututxline(&s_utent);
   endutxent();
+#if !defined(__FreeBSD__)
   updwtmpx(WTMPX_FILE, &s_utent);
+#endif
 }
 
 void
@@ -1235,7 +1244,9 @@ vsf_remove_uwtmp(void)
   (void) pututxline(&s_utent);
   endutxent();
   s_utent.ut_tv.tv_sec = vsf_sysutil_get_time_sec();
+#if !defined(__FreeBSD__)
   updwtmpx(WTMPX_FILE, &s_utent);
+#endif
 }
 
 #endif /* !VSF_SYSDEP_HAVE_UTMPX */
