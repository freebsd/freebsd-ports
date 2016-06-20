--- eights.c.orig	2016-06-20 14:33:50 UTC
+++ eights.c
@@ -5,6 +5,8 @@
 #include <unistd.h>
 #include <time.h> 
 
+#define debug 
+
 #ifdef DEBUG
 #undef debug
 #define debug printf
