--- ./chess.h.orig	2010-08-11 11:20:40.000000000 +0200
+++ ./chess.h	2010-08-11 11:20:49.000000000 +0200
@@ -24,7 +24,7 @@
 #include <stdio.h>
 #include <assert.h>
 #include <stdlib.h>
-#if !defined(IPHONE)
+#if !defined(IPHONE) && !defined(__FreeBSD__)   
 #  include <malloc.h>
 #endif
 #include <string.h>
