--- libimage/open.c.orig	Sat Oct 14 12:46:09 2000
+++ libimage/open.c	Sat Mar 24 20:27:50 2007
@@ -8,6 +8,17 @@
 #include	<stdlib.h>
 #include	"image.h"
 
+#ifdef __FreeBSD__
+	#include <machine/endian.h>
+	#if BYTE_ORDER == LITTLE_ENDIAN
+		#define DOREV	1
+	#else
+		#define DOREV	0
+	#endif
+#else
+	#define DOREV	0
+#endif
+
 void cvtlongs(int buffer[],int n);
 void cvtimage(int buffer[]);
 void i_seterror(void (*func)());
@@ -80,7 +91,7 @@
 		image->max = 0;
 		isetname(image,"no name"); 
 		image->wastebytes = 0;
-		image->dorev = 0;
+		image->dorev = DOREV;
 		if (write(f,image,sizeof(IMAGE)) != sizeof(IMAGE)) {
 		    free(image);
 		    close(f);
