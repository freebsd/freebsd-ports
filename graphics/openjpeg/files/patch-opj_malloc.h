--- libopenjpeg/opj_malloc.h.orig	2013-10-08 17:19:09.755013928 +0200
+++ libopenjpeg/opj_malloc.h	2013-10-08 17:20:11.403012744 +0200
@@ -85,8 +85,7 @@
 		#define HAVE_MEMALIGN
 	/* Linux x86_64 and OSX always align allocations to 16 bytes */
 	#elif !defined(__amd64__) && !defined(__APPLE__)	
-		#define HAVE_MEMALIGN
-		#include <malloc.h>			
+		#include <stdlib.h>
 	#endif
 #endif
 
