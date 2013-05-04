--- langscan/_template.c.orig	2006-09-19 00:20:44.000000000 +0900
+++ langscan/_template.c	2013-05-03 21:25:11.000000000 +0900
@@ -11,7 +11,11 @@
  */
 
 
-#include <ruby.h>
+#ifdef HAVE_RUBY_ST_H
+# include "ruby/ruby.h"
+#else
+# include "ruby.h"
+#endif
 #include "langname.h"
 
 static VALUE token_symbol_list[
