--- zzip/zzip.h.orig	Fri Aug  1 07:20:41 2003
+++ zzip/zzip.h	Fri Aug  1 07:20:57 2003
@@ -21,6 +21,7 @@
 
 #include <zzip/conf.h>
 
+#include <sys/types.h>
 #include <fcntl.h>
 #include <stddef.h> /* size_t and friends */
 /* msvc6 has neither ssize_t (we assume "int") nor off_t (assume "long") */
