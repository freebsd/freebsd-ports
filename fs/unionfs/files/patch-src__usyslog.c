--- src/usyslog.c.orig	2015-01-14 10:08:20 UTC
+++ src/usyslog.c
@@ -23,7 +23,7 @@
 
 #if __APPLE__
 #include <malloc/malloc.h>
-#else
+#elif !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 
