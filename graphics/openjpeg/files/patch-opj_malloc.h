--- libopenjpeg/opj_malloc.h.orig	2012-02-07 11:49:55.000000000 +0100
+++ libopenjpeg/opj_malloc.h	2012-06-02 11:25:56.000000000 +0200
@@ -85,8 +85,7 @@
 		#define HAVE_MEMALIGN
 	/* Linux x86_64 and OSX always align allocations to 16 bytes */
 	#elif !defined(__amd64__) && !defined(__APPLE__)	
-		#define HAVE_MEMALIGN
-		#include <malloc.h>			
+		#include <stdlib.h>			
 	#endif
 #endif
 
