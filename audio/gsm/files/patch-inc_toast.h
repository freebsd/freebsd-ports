--- inc/toast.h.orig	2020-12-25 18:27:45 UTC
+++ inc/toast.h
@@ -15,6 +15,7 @@
 #define _POSIX_C_SOURCE 200809L
 #endif
 
+#include <sys/time.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 
