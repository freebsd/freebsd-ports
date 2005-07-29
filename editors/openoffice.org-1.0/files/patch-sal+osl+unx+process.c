--- sal/osl/unx/process.c.orig	Wed Jun  5 16:24:42 2002
+++ sal/osl/unx/process.c	Wed Jan 15 01:25:17 2003
@@ -222,7 +222,7 @@
 	/* Memory layout of CMD_ARG_PRG:
        progname\0arg1\0...argn[\0]\0environ\0env2\0...envn\0[\0] */
 
-#if !defined(NETBSD)
+#if !defined(NETBSD) && !defined(FREEBSD)
 	extern sal_Char*  CMD_ARG_PRG;
 #endif
 	extern sal_Char** CMD_ARG_ENV;
@@ -862,7 +862,7 @@
 
 			if (! INIT_GROUPS(data.m_name, data.m_gid) || (setuid(data.m_uid) != 0))
 				OSL_TRACE("Failed to change uid and guid, errno=%d (%s)\n", errno, strerror(errno));
-#ifdef LINUX
+#if defined(LINUX) || defined(FREEBSD)
 			unsetenv("HOME");
 #else
 			putenv("HOME=");
