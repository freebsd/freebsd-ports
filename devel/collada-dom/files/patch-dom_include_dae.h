--- dom/include/dae.h.orig	2017-10-21 05:05:24 UTC
+++ dom/include/dae.h
@@ -25,7 +25,7 @@
 #pragma warning(disable: 4180 4245)
 #endif
 #ifndef NO_BOOST
-#include <boost/filesystem/convenience.hpp>
+#include <boost/filesystem.hpp>
 #endif
 #ifdef _MSC_VER
 #pragma warning(pop)
