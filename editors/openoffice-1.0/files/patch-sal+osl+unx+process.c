--- ../sal/osl/unx/process.c.orig	Wed Jan  9 13:07:41 2002
+++ ../sal/osl/unx/process.c	Wed Apr  3 00:59:53 2002
@@ -833,7 +833,7 @@
 
 			if (! INIT_GROUPS(data.m_name, data.m_gid) || (setuid(data.m_uid) != 0))
 				OSL_TRACE("Failed to change uid and guid, errno=%d (%s)\n", errno, strerror(errno));
-#ifdef LINUX
+#if defined(LINUX) || defined(FREEBSD)
 			unsetenv("HOME");
 #else
 			putenv("HOME=");
