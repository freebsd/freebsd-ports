Index: src/wtmp.c
===================================================================
RCS file: /cvsroot/proftp/proftpd/src/wtmp.c,v
retrieving revision 1.2
diff -u -r1.2 wtmp.c
--- src/wtmp.c	18 Feb 2009 18:24:50 -0000	1.2
+++ src/wtmp.c	13 Mar 2010 17:06:33 -0000
@@ -37,7 +37,8 @@
   int res = 0;
 
 #if ((defined(SVR4) || defined(__SVR4)) || \
-    (defined(__NetBSD__) && defined(HAVE_UTMPX_H))) && \
+    (defined(__NetBSD__) && defined(HAVE_UTMPX_H)) || \
+    (defined(__FreeBSD_version) && __FreeBSD_version >= 900007 && defined(HAVE_UTMPX_H))) && \
     !(defined(LINUX) || defined(__hpux) || defined (_AIX))
   /* This "auxilliary" utmp doesn't exist under linux. */
 
@@ -51,8 +52,17 @@
 
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
@@ -81,6 +91,9 @@
     memcpy(&utx.ut_ss, pr_netaddr_get_inaddr(ip), sizeof(utx.ut_ss));
     gettimeofday(&utx.ut_tv, NULL);
 
+#elif defined(__FreeBSD_version) && __FreeBSD_version >= 900007 && defined(HAVE_UTMPX_H)
+    gettimeofday(&utx.ut_tv, NULL);
+
 #else /* SVR4 */
     utx.ut_syslen = strlen(utx.ut_host)+1;
 
