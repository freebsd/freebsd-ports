--- src.bak/updatedd.c	Tue Dec  2 15:50:39 2003
+++ src/updatedd.c	Tue Dec  2 15:50:58 2003
@@ -33,11 +33,7 @@
 #define MAXLIBS		10
 #define MAXDATA		256
 
-#ifndef __linux__
-# define LIB_FUNC	"_dyndns"
-#else
-# define LIB_FUNC	"dyndns"
-#endif
+#define LIB_FUNC	"dyndns"
 
 typedef void (*fptr)(int, char**);
 
