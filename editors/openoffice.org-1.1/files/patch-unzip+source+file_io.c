--- ../unzip/source/file_io.c.orig	Tue Mar  5 18:32:38 2002
+++ ../unzip/source/file_io.c	Tue Mar  5 18:40:50 2002
@@ -500,7 +500,7 @@
 #ifdef MPW
 				pCallBack( 0 );
 #else
-				#if defined LINUX || defined MACOSX || defined NETBSD
+				#if defined LINUX || defined MACOSX || defined NETBSD || defined FREEBSD
 				pCallBack( lseek(outfd, 0, SEEK_CUR) );
 				#else
 				pCallBack( tell( outfd ) );
@@ -860,8 +860,11 @@
 /*  extern char *_TZ;   no longer used? */
 #else /* !AMIGA */
 #   define YRBASE  1970
-#ifdef BSD
-#ifndef __386BSD__
+#ifdef FREEBSD
+#include <sys/types.h>
+#endif */ FREEBSD */
+#if defined BSD || defined FREEBSD
+#if !defined __386BSD__ && !defined FREEBSD
 	static struct timeb tbp;
 #endif /* !__386BSD__ */
 #else /* !BSD */
@@ -932,8 +935,8 @@
 	/* convert date & time to seconds relative to 00:00:00, 01/01/YRBASE */
 	m_time = ((days + dy) * 86400) + (hh * 3600) + (mm * 60) + ss;
 
-#if defined BSD && ! defined MACOSX && ! defined NETBSD
-#ifndef __386BSD__
+#if (defined BSD || defined FREEBSD) && ! defined MACOSX && ! defined NETBSD
+#if !defined __386BSD__ && !defined FREEBSD
 	ftime(&tbp);
 	m_time += tbp.timezone * 60L;
 #endif
