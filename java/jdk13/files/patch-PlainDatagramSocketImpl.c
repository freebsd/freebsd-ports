$FreeBSD$

diff -u -r1.3 PlainDatagramSocketImpl.c
--- ../src/solaris/native/java/net/PlainDatagramSocketImpl.c	19 Aug 2001 05:46:50 -0000	1.3
+++ ../src/solaris/native/java/net/PlainDatagramSocketImpl.c	31 Oct 2002 16:39:39 -0000
@@ -489,7 +489,7 @@
 			strerror(errno));
 	return;
     }
-#if defined(__linux__) && defined(SO_BROADCAST)
+#if (defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)) && defined(SO_BROADCAST)
      {
         int t = 1;
         setsockopt(fd, SOL_SOCKET, SO_BROADCAST, (char*) &t, sizeof(int));
