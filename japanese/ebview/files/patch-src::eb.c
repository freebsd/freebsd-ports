--- src/eb.c.orig	Mon Nov 18 18:13:06 2002
+++ src/eb.c	Sat Nov 30 09:04:05 2002
@@ -24,6 +24,7 @@
 #include <iconv.h>
 #include <langinfo.h>
 #include <wchar.h>
+#include <pthread.h>
 
 
 #define MAX_HITS            50
