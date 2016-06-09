--- src/nvim/shada.c.orig	2016-04-25 01:46:34 UTC
+++ src/nvim/shada.c
@@ -46,7 +46,6 @@
 #ifdef HAVE_BE64TOH
 # define _BSD_SOURCE 1
 # define _DEFAULT_SOURCE 1
-# include <endian.h>
 #endif
 
 // Note: when using bufset hash pointers are intentionally casted to uintptr_t
