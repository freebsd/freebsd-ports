--- lib/external/libwolv/libs/net/include/wolv/net/common.hpp.orig	2023-07-09 14:37:57 UTC
+++ lib/external/libwolv/libs/net/include/wolv/net/common.hpp
@@ -16,6 +16,8 @@
 
 #endif
 
+#include <iterator>
+
 namespace wolv::net {
 
     #if defined(OS_WINDOWS)
