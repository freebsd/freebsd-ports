--- stress-resources.c.orig	2019-06-21 10:48:56 UTC
+++ stress-resources.c
@@ -178,7 +178,9 @@ static void NORETURN waste_resources(
 		info[i].m_mmap = MAP_FAILED;
 		info[i].pipe_ret = -1;
 		info[i].fd_open = -1;
+#if defined(HAVE_EVENTFD)
 		info[i].fd_ev = -1;
+#endif
 #if defined(HAVE_MEMFD_CREATE)
 		info[i].fd_memfd = -1;
 #endif
