--- src/mkcmdtab.c.orig	2025-12-15 09:04:17 UTC
+++ src/mkcmdtab.c
@@ -14,11 +14,7 @@
 
 #include "vim.h"
 
-#if defined(UTS4) || defined(__CYGWIN__)
-    int
-#else
-	void
-#endif
+int
 main(argc, argv)
 	int		argc;
 	char	**argv;
