--- uuid-utils.cc.orig	2024-09-30 10:32:35 UTC
+++ uuid-utils.cc
@@ -31,6 +31,7 @@
 #endif /* BOOST_VERSION */
 
 #include <boost/random/mersenne_twister.hpp>
+#include <boost/uuid/uuid.hpp>
 #include <boost/uuid/uuid_generators.hpp>
 
 // The default of:
