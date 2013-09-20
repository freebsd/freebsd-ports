--- libbif.c	2012-05-14 23:13:03.000000000 -0700
+++ libbif.c	2012-05-14 23:13:42.000000000 -0700
@@ -27,7 +27,7 @@
 #include <string.h>
 #endif
 
-#if defined(linux) || defined(__DragonFly__) || defined(IOZ_macosx)
+#if defined(linux) || defined(__DragonFly__) || defined(IOZ_macosx) || defined(__FreeBSD__)
 #include <unistd.h>
 #include <stdlib.h>
 #endif
