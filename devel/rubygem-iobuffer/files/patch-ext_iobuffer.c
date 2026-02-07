--- ext/iobuffer.c.orig	2022-03-10 08:57:25 UTC
+++ ext/iobuffer.c
@@ -5,7 +5,7 @@
  */
 
 #include "ruby.h"
-#include "rubyio.h"
+#include "ruby/io.h"
 
 #include <assert.h>
 
