--- dns_random.cc.orig	2018-11-29 12:53:42 UTC
+++ dns_random.cc
@@ -40,7 +40,9 @@
 #include <openssl/rand.h>
 #endif
 #if defined(HAVE_GETRANDOM)
+extern "C" {
 #include <sys/random.h>
+}
 #endif
 
 static enum DNS_RNG {
