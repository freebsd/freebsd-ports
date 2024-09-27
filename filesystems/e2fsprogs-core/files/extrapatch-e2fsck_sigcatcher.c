--- e2fsck/sigcatcher.c.orig	2020-01-06 23:10:17 UTC
+++ e2fsck/sigcatcher.c
@@ -17,6 +17,7 @@
 #ifdef HAVE_EXECINFO_H
 #include <execinfo.h>
 #endif
+#include <libunwind.h>
 
 #include "e2fsck.h"
 
@@ -376,7 +377,7 @@ static void die_signal_handler(int signum, siginfo_t *
 	       void *stack_syms[32];
 	       int frames;
 
-	       frames = backtrace(stack_syms, 32);
+	       frames = unw_backtrace(stack_syms, 32);
 	       backtrace_symbols_fd(stack_syms, frames, 2);
        }
 #endif
