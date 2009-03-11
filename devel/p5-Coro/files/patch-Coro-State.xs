--- Coro/State.xs.orig	2008-12-16 03:39:29.000000000 +0800
+++ Coro/State.xs	2009-03-11 23:28:09.000000000 +0800
@@ -155,6 +155,10 @@
 #include "CoroAPI.h"
 #define GCoroAPI (&coroapi) /* very sneaky */
 
+#ifndef PERL_MAGIC_ext
+#   define PERL_MAGIC_ext            '~'
+#endif
+
 #ifdef USE_ITHREADS
 # if CORO_PTHREAD
 static void *coro_thx;
