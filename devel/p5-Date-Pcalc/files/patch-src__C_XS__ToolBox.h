--- ./src/C_XS/ToolBox.h.orig	2009-10-15 18:31:02.000000000 +0200
+++ ./src/C_XS/ToolBox.h	2013-07-25 16:06:05.000000000 +0200
@@ -93,6 +93,8 @@
     #elif PERL_DARWIN
         #define boolean bool
     #else
+        #undef false
+        #undef true
         typedef enum { false = FALSE, true = TRUE } boolean;
     #endif
 #endif
