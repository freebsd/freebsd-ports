--- ext/lib/Utilities/BinUtils.hpp.orig	2014-10-11 11:19:24 UTC
+++ ext/lib/Utilities/BinUtils.hpp
@@ -54,6 +54,7 @@
 
 #include "Exception.hpp"
 
+#include <machine/endian.h>
 #ifndef BYTE_ORDER
 #ifdef _MSC_VER
 #define LITTLE_ENDIAN 1
