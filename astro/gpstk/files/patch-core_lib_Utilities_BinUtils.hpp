--- core/lib/Utilities/BinUtils.hpp.orig	2017-08-01 17:51:01 UTC
+++ core/lib/Utilities/BinUtils.hpp
@@ -57,6 +57,7 @@
 #include "Exception.hpp"
 #include <memory.h>
 
+#include <machine/endian.h>
 #ifndef BYTE_ORDER
 #ifdef _MSC_VER
 #define LITTLE_ENDIAN 1
