--- include/gn/gnFileContig.h.orig	Wed Jul 18 01:52:09 2001
+++ include/gn/gnFileContig.h	Sun Dec 22 12:51:21 2002
@@ -17,7 +17,7 @@
 
 #include <string>
 #include "gn/gnClone.h"
-#ifdef __GNUG__
+#if (defined(__GNUC__) && (__GNUC__) < 3)
 #include "pair.h"
 #endif
 
