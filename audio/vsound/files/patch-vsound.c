--- vsound.c.orig	Tue Apr 13 16:52:15 2004
+++ vsound.c	Tue Apr 13 17:01:30 2004
@@ -70,11 +70,11 @@
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
