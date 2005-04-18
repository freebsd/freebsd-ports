--- include/post-config.h.orig	Thu Mar 24 18:41:45 2005
+++ include/post-config.h	Mon Apr 18 17:52:16 2005
@@ -142,4 +142,8 @@
 # include "trio.h"
 #endif
 
+#if __FreeBSD__ < 5
+	#define atoll(n)	strtoll((n),NULL,10)
+#endif
+
 #endif /* POST_CONFIG_H */
