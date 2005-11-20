--- simgear/misc/stdint.hxx.orig	Sun Nov 20 05:16:55 2005
+++ simgear/misc/stdint.hxx	Sun Nov 20 05:17:02 2005
@@ -51,7 +51,7 @@
 #elif defined(sgi) || defined(__sun)
 # include <sys/types.h>
 #else
-# include <stdint.h>
+# include <unistd.h>
 #endif
 
 
