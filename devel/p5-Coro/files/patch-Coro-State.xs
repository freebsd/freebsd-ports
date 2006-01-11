--- Coro/State.xs.orig	Tue Aug 10 03:54:35 2004
+++ Coro/State.xs	Tue Aug 10 16:22:54 2004
@@ -57,6 +57,10 @@
 
 #include "CoroAPI.h"
 
+#ifndef PERL_MAGIC_ext
+#   define PERL_MAGIC_ext            '~'
+#endif
+
 #ifdef USE_ITHREADS
 static perl_mutex coro_mutex;
 # define LOCK   do { MUTEX_LOCK (&coro_mutex);   } while (0)
