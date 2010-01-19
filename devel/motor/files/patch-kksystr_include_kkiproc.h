--- kksystr/include/kkiproc.h.orig	2010-01-19 11:48:25.000000000 +0100
+++ kksystr/include/kkiproc.h	2010-01-19 11:48:55.000000000 +0100
@@ -9,7 +9,9 @@
 #include <string.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#ifdef __linux__
 #include <utmp.h>
+#endif
 #include <string.h>
 #include <ctype.h>
 
