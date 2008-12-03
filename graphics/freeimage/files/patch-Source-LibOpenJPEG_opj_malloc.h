--- Source/LibOpenJPEG/opj_malloc.h.orig	2008-12-03 16:48:35.000000000 +0100
+++ Source/LibOpenJPEG/opj_malloc.h	2008-12-03 16:49:08.000000000 +0100
@@ -77,7 +77,9 @@
 		#define HAVE_MEMALIGN
 	/* Linux x86_64 and OSX always align allocations to 16 bytes */
 	#elif !defined(__amd64__) && !defined(__APPLE__)	
+	#ifndef __FreeBSD__
 		#define HAVE_MEMALIGN
+	#endif
 		#include <malloc.h>			
 	#endif
 #endif
