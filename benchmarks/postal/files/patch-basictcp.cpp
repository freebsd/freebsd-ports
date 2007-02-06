--- basictcp.cpp.orig	Tue Feb  6 16:03:18 2007
+++ basictcp.cpp	Tue Feb  6 16:03:53 2007
@@ -14,8 +14,10 @@
 #include "logit.h"
 #include "results.h"
 
+#ifndef USE_OPENSSL
 int base_tcp::m_init_dh_params = 0;
 gnutls_dh_params_t base_tcp::m_dh_params;
+#endif
 
 base_tcp::base_tcp(int fd, Logit *log, Logit *debug, results *res
 #ifdef USE_SSL
