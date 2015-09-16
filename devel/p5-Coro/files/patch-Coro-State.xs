--- Coro/State.xs.orig	2015-06-30 12:32:08 UTC
+++ Coro/State.xs
@@ -102,6 +102,10 @@ static int cctx_max_idle = 4;
 #include "CoroAPI.h"
 #define GCoroAPI (&coroapi) /* very sneaky */
 
+#ifndef PERL_MAGIC_ext
+#   define PERL_MAGIC_ext            '~'
+#endif
+
 #ifdef USE_ITHREADS
 # if CORO_PTHREAD
 static void *coro_thx;
