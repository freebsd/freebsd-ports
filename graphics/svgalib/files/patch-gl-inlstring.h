--- gl/inlstring.h.orig	Fri Aug 25 05:11:26 2000
+++ gl/inlstring.h	Fri Aug 25 05:11:36 2000
@@ -1,6 +1,6 @@
 /* Based on functions in linux/string.h */
 
-#include <linux/types.h>	/* for size_t */
+#include <sys/types.h>	/* for size_t */
 
 #if defined(__alpha__) || defined (NO_ASSEMBLY)
 
