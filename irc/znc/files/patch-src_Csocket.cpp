--- src/Csocket.cpp.orig	2015-11-15 17:54:20 UTC
+++ src/Csocket.cpp
@@ -47,6 +47,7 @@
 #include <stdio.h>
 #include <openssl/conf.h>
 #include <openssl/engine.h>
+#include <openssl/comp.h>
 #endif /* HAVE_LIBSSL */
 
 #ifdef HAVE_ICU
