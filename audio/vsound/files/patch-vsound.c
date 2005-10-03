--- vsound.c.orig	Sat Jul 10 23:29:33 2004
+++ vsound.c	Tue Oct  4 00:20:25 2005
@@ -73,11 +73,11 @@
 /*------------------------------------------------------------------------------
 ** Macros to handle big/little endian issues.
 */
-#if HAVE_ENDIAN_H
+#ifdef HAVE_ENDIAN_H
 	/* This is the best way to do it. Unfortunately Sparc Solaris (and
 	** possibly others) don't have <endian.h>
 	*/
-	#include	<endian.h>
+	#include	<sys/endian.h>
 	#if (__BYTE_ORDER == __LITTLE_ENDIAN)
 		#define	CPU_IS_LITTLE_ENDIAN		1
 		#define	CPU_IS_BIG_ENDIAN			0
@@ -210,7 +210,7 @@
 	dsp_init () ;
 
 	va_start (args, flags) ;
-	mode = va_arg (args, mode_t) ;
+	mode = va_arg (args, int) ;
 	va_end (args) ;
 
 	if (strcmp (pathname, "/dev/dsp"))
