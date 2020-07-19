--- lib-src/portsmf/allegro.h.orig	2020-07-18 17:54:26 UTC
+++ lib-src/portsmf/allegro.h
@@ -51,6 +51,7 @@
 #include <assert.h>
 #include <istream>
 #include <ostream>
+#include <cstring>
 
 #define ALG_EPS 0.000001 // epsilon
 #define ALG_DEFAULT_BPM 100.0 // default tempo
