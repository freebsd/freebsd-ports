--- gr-vocoder/lib/gsm_fr_decode_ps_impl.h.orig	2020-02-16 18:48:02 UTC
+++ gr-vocoder/lib/gsm_fr_decode_ps_impl.h
@@ -26,7 +26,11 @@
 #include <gnuradio/vocoder/gsm_fr_decode_ps.h>
 
 extern "C" {
+#ifdef __FreeBSD__
+#include <gsm.h>
+#else
 #include "gsm.h"
+#endif
 }
 
 namespace gr {
