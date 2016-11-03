--- Coro/State.xs.orig	2016-06-26 21:44:30 UTC
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
@@ -1412,7 +1416,11 @@ runops_trace (pTHX)
                           PUSHMARK (SP);
                           PUSHs (&PL_sv_yes);
                           PUSHs (fullname);
+#if PERL_VERSION_ATLEAST(5,24,0)
+                          PUSHs (CxHASARGS (cx) ? sv_2mortal (newRV_inc (PL_curpad[0])) : &PL_sv_undef);
+#else
                           PUSHs (CxHASARGS (cx) ? sv_2mortal (newRV_inc ((SV *)cx->blk_sub.argarray)) : &PL_sv_undef);
+#endif
                           PUTBACK;
                           cb = hv_fetch ((HV *)SvRV (coro_current), "_trace_sub_cb", sizeof ("_trace_sub_cb") - 1, 0);
                           if (cb) call_sv (*cb, G_KEEPERR | G_EVAL | G_VOID | G_DISCARD);
