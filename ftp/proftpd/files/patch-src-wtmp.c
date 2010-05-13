--- src/wtmp.c.orig	2009-02-18 19:24:50.000000000 +0100
+++ src/wtmp.c	2010-05-13 16:18:54.711790750 +0200
@@ -37,7 +37,9 @@
   int res = 0;
 
 #if ((defined(SVR4) || defined(__SVR4)) || \
-    (defined(__NetBSD__) && defined(HAVE_UTMPX_H))) && \
+    ((defined(__NetBSD__) || \
+     (defined(__FreeBSD_version) && __FreeBSD_version >= 900007)) && \
+      defined(HAVE_UTMPX_H))) && \
     !(defined(LINUX) || defined(__hpux) || defined (_AIX))
   /* This "auxilliary" utmp doesn't exist under linux. */
 
@@ -51,8 +53,17 @@
 
   static int fdx = -1;
 
-#if !defined(WTMPX_FILE) && defined(_PATH_WTMPX)
-# define WTMPX_FILE _PATH_WTMPX
+#if !defined(WTMPX_FILE)
+# if defined(_PATH_WTMPX)
+#   define WTMPX_FILE _PATH_WTMPX
+# elif defined(_PATH_UTMPX)
+#   define WTMPX_FILE _PATH_UTMPX
+# else
+/* This path works for FreeBSD; not sure what to do for other platforms which
+ * don't define _PATH_WTMPX or _PATH_UTMPX.
+ */
+#   define WTMPX_FILE "/var/log/utx.log"
+# endif
 #endif
 
   if (fdx < 0 &&
@@ -80,7 +91,8 @@
 #if defined(__NetBSD__) && defined(HAVE_UTMPX_H)
     memcpy(&utx.ut_ss, pr_netaddr_get_inaddr(ip), sizeof(utx.ut_ss));
     gettimeofday(&utx.ut_tv, NULL);
-
+#elif defined(__FreeBSD_version) && __FreeBSD_version >= 900007 && defined(HAVE_UTMPX_H)
+    gettimeofday(&utx.ut_tv, NULL);
 #else /* SVR4 */
     utx.ut_syslen = strlen(utx.ut_host)+1;
 
@@ -113,7 +125,9 @@
   }
 
 #else /* Non-SVR4 systems */
+#if !defined(__FreeBSD_version) || __FreeBSD_version < 900007 || !defined(HAVE_UTMPX_H)
   struct utmp ut;
+#endif
   static int fd = -1;
 
   if (fd < 0 &&
