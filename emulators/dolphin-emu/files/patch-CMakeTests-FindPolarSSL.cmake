Add missing header for strlen()

--- CMakeTests/FindPolarSSL.cmake.orig	2015-10-05 20:23:44.048812679 +0000
+++ CMakeTests/FindPolarSSL.cmake	2015-10-05 20:26:09.643030106 +0000
@@ -34,6 +34,8 @@
 	set(CMAKE_REQUIRED_LIBRARIES ${POLARSSL_LIBRARY})
 	unset(POLARSSL_WORKS CACHE)
 	check_cxx_source_compiles("
+	#include <cstring>
+
 	#include <polarssl/ctr_drbg.h>
 	#include <polarssl/entropy.h>
 	#include <polarssl/net.h>
