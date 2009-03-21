--- libopenjpeg/opj_malloc.h.orig	2007-12-21 11:19:01.000000000 +0100
+++ libopenjpeg/opj_malloc.h	2009-03-21 12:02:37.000000000 +0100
@@ -76,8 +76,15 @@
 	#if defined(__sun)
 			#define HAVE_MEMALIGN
 		#elif defined(__GNUC__)
+			#if defined(__FreeBSD__)
+			#include <stdlib.h>
+			#include <osreldate.h>
+			#if __FreeBSD_versioni >= 700000 
+			#endif
+			#else
 			#define HAVE_MEMALIGN
 			#include <malloc.h>		
+			#endif
 		/* Linux x86_64 and OSX always align allocations to 16 bytes */
 		#elif !defined(__amd64__) && !defined(__APPLE__)	
 			/* FIXME: Yes, this is a big assumption */
