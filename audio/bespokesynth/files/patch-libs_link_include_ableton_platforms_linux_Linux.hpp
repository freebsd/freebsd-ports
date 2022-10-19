--- libs/link/include/ableton/platforms/linux/Linux.hpp.orig	2022-07-08 19:03:39 UTC
+++ libs/link/include/ableton/platforms/linux/Linux.hpp
@@ -19,7 +19,7 @@
 
 #pragma once
 
-#include <byteswap.h>
+#include <infiniband/byteswap.h>
 
 #ifndef ntohll
 #define ntohll(x) bswap_64(x)
