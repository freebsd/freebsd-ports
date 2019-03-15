--- gr-vocoder/lib/gsm_fr_encode_sp_impl.h.orig	2019-03-13 15:22:30 UTC
+++ gr-vocoder/lib/gsm_fr_encode_sp_impl.h
@@ -26,7 +26,11 @@
 #include <gnuradio/vocoder/gsm_fr_encode_sp.h>
 
 extern "C"{
+#ifdef __FreeBSD__
+#include <gsm.h>
+#else
 #include "gsm/gsm.h"
+#endif
 }
 
 namespace gr {
