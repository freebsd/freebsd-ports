--- eights.c	Sun Nov 10 08:50:52 2002
+++ eights.c	Sat May 20 12:36:22 2000
@@ -5,6 +5,8 @@
 #include <unistd.h>
 #include <time.h> 
 
+#define debug 
+
 #ifdef DEBUG
 #undef debug
 #define debug printf
