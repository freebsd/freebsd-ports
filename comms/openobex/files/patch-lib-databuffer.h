--- lib/databuffer.h.orig	Thu May  4 13:24:21 2006
+++ lib/databuffer.h	Sat Nov 25 22:02:38 2006
@@ -31,7 +31,7 @@
 #define DATABUFFER_H
 
 #define __need_size_t
-#include <stddef.h>
+#include <sys/types.h>
 #include <stdint.h>
 
 /*
