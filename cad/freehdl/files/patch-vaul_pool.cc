--- vaul/pool.cc.orig	2005-12-14 08:23:06.000000000 +0000
+++ vaul/pool.cc
@@ -24,6 +24,7 @@
 #include <freehdl/vaul-lexer.h>
 #include <freehdl/vaul-util.h>
 
+#include <stdlib.h>
 #if HAVE_MALLOC_H
 #include <malloc.h>
 #endif
