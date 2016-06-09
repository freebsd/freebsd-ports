--- src/nvim/shada.c.orig	2016-06-05 14:13:28 UTC
+++ src/nvim/shada.c
@@ -46,7 +46,7 @@
 #ifdef HAVE_BE64TOH
 # define _BSD_SOURCE 1
 # define _DEFAULT_SOURCE 1
-# include <endian.h>
+# include ENDIAN_INCLUDE_FILE
 #endif
 
 // Note: when using bufset hash pointers are intentionally casted to uintptr_t
