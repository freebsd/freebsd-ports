--- gr-vocoder/lib/gsm_fr_decode_ps_impl.h.orig	2024-01-17 20:36:19 UTC
+++ gr-vocoder/lib/gsm_fr_decode_ps_impl.h
@@ -14,7 +14,11 @@ extern "C" {
 #include <gnuradio/vocoder/gsm_fr_decode_ps.h>
 
 extern "C" {
+#ifdef __FreeBSD__
+#include <gsm.h>
+#else
 #include "gsm.h"
+#endif
 }
 
 namespace gr {
