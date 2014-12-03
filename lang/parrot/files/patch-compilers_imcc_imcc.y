--- compilers/imcc/imcc.y.orig	2013-01-28 19:57:42 UTC
+++ compilers/imcc/imcc.y
@@ -45,7 +45,7 @@ This file contains the grammar of the PI
 
 /* prevent declarations of malloc() and free() in the generated parser. */
 #define YYMALLOC
-#define YYFREE(Ptr) do { /* empty */; } while (YYID (0))
+#define YYFREE(Ptr) do { /* empty */; } while (0)
 
 #ifndef YYENABLE_NLS
 #  define YYENABLE_NLS 0
