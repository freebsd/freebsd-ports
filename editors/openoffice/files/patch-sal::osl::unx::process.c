--- ../sal/osl/unx/process.c.orig	Sat Mar  2 22:33:17 2002
+++ ../sal/osl/unx/process.c	Sat Mar  2 22:33:58 2002
@@ -834,7 +834,7 @@
 
 			if (! INIT_GROUPS(data.m_name, data.m_gid) || (setuid(data.m_uid) != 0))
 				OSL_TRACE("Failed to change uid and guid, errno=%d (%s)\n", errno, strerror(errno));
-#ifdef LINUX
+#if defined(LINUX) || defined(FREEBSD)
 			unsetenv("HOME");
 #else
 			putenv("HOME=");
