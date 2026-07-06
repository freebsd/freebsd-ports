--- version.c.orig	2023-03-08 04:43:11 UTC
+++ version.c
@@ -13,7 +13,11 @@
 
 #include "def.h"
 
+#ifdef VERSION
+const char	version[] = "Mg 2a (" VERSION ")";
+#else
 const char	version[] = "Mg 2a";
+#endif
 
 /*
  * Display the version. All this does
