FreeBSD support

--- unzip/source/file_io.c.orig	Sat Apr  6 12:13:38 2002
+++ unzip/source/file_io.c	Wed May  1 22:34:51 2002
@@ -864,7 +864,7 @@
 #ifndef __386BSD__
 	static struct timeb tbp;
 #endif /* !__386BSD__ */
-#elif !defined(NETBSD) /* !BSD */
+#elif (!defined(NETBSD) && !defined(FREEBSD))/* !BSD */
 	extern long timezone;
 #endif /* ?BSD */
 #endif /* ?AMIGA */
