--- include/gn/gnSourceHeader.h.orig	Tue Oct 16 02:59:53 2001
+++ include/gn/gnSourceHeader.h	Sun Dec 22 12:50:29 2002
@@ -19,7 +19,7 @@
 #include "gn/gnBaseHeader.h"
 #include "gn/gnBaseSource.h"
 
-#ifdef __GNUG__
+#if (defined(__GNUC__) && (__GNUC__) < 3)
 #include "pair.h"
 #endif
 
