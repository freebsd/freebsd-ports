--- ../unzip/source/file_io.c.orig	Sat Oct 19 11:58:45 2002
+++ ../unzip/source/file_io.c	Sat Oct 19 12:03:40 2002
@@ -500,7 +500,7 @@
 #ifdef MPW
 				pCallBack( 0 );
 #else
-				#if defined LINUX || defined MACOSX || defined NETBSD
+				#if defined LINUX || defined MACOSX || defined NETBSD || defined FREEBSD
 				pCallBack( lseek(outfd, 0, SEEK_CUR) );
 				#else
 				pCallBack( tell( outfd ) );
@@ -865,7 +865,9 @@
 	static struct timeb tbp;
 #endif /* !__386BSD__ */
 #else /* !BSD */
+#if (!defined(NETBSD) && !defined(FREEBSD))
 	extern long timezone;
+#endif /* !defined(NETBSD) && !defined(FREEBSD) */
 #endif /* ?BSD */
 #endif /* ?AMIGA */
 
