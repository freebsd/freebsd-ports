--- include/gn/gnSourceQualifier.h.orig	Tue Oct 16 02:59:53 2001
+++ include/gn/gnSourceQualifier.h	Sun Dec 22 12:48:20 2002
@@ -19,7 +19,7 @@
 #include "gn/gnBaseQualifier.h"
 #include "gn/gnBaseSource.h"
 
-#ifdef __GNUG__
+#if (defined(__GNUC__) && (__GNUC__) < 3)
 #include "pair.h"
 #endif
 
