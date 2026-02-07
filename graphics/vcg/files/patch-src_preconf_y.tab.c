--- 1.1	1995/02/18 17:07:16
+++ src/preconf/y.tab.c	1995/02/18 17:20:13
@@ -446,7 +446,7 @@
 
 #ifndef YY_MALLOC_DECL
 #define YY_MALLOC_DECL
-#include <malloc.h>
+#include <stdlib.h>
 #endif
  
 #undef YYVALGLOBAL
@@ -5815,7 +5815,7 @@
 
 
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 #ifdef ANSI_C
 #include <stdarg.h>
 #else
