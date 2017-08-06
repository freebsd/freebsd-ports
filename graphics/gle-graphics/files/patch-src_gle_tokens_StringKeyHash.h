--- src/gle/tokens/StringKeyHash.h.orig	2012-02-19 21:07:34 UTC
+++ src/gle/tokens/StringKeyHash.h
@@ -75,10 +75,12 @@
 using namespace std;
 
 #ifndef GCC2
+#ifndef _LIBCPP_VERSION
 #ifndef _MSC_VER
 	using namespace __gnu_cxx;  // using gnu extensions such as "hash"
 #endif
 #endif
+#endif
 
 #include "RefCount.h"
 #include "BinIO.h"
