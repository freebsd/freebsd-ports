--- src/mkcmdtab.c.orig	2010-05-29 01:52:51.281691000 +0900
+++ src/mkcmdtab.c	2010-05-29 01:54:05.558527228 +0900
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
