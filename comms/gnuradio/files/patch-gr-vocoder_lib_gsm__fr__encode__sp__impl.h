--- gr-vocoder/lib/gsm_fr_encode_sp_impl.h.orig	2019-05-29 03:34:08 UTC
+++ gr-vocoder/lib/gsm_fr_encode_sp_impl.h
@@ -26,7 +26,11 @@
 #include <gnuradio/vocoder/gsm_fr_encode_sp.h>
 
 extern "C"{
+#ifdef __FreeBSD__
+#include <gsm.h>
+#else
 #include "gsm.h"
+#endif
 }
 
 namespace gr {
