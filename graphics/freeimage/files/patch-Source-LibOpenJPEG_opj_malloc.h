--- Source/LibOpenJPEG/opj_malloc.h.orig
+++ Source/LibOpenJPEG/opj_malloc.h
@@ -85,8 +85,10 @@
 		#define HAVE_MEMALIGN
 	/* Linux x86_64 and OSX always align allocations to 16 bytes */
 	#elif !defined(__amd64__) && !defined(__APPLE__)	
+	#ifndef __FreeBSD__
 		#define HAVE_MEMALIGN
-		#include <malloc.h>			
+	#endif
+		#include <stdlib.h>
 	#endif
 #endif
 
