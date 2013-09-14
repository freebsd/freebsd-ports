--- src/i18n.cc.orig	2012-04-23 13:46:49.000000000 +0400
+++ src/i18n.cc	2013-09-13 20:18:48.792226136 +0400
@@ -27,6 +27,7 @@
 
 #include <cstdlib>
 #include <utility>
+#include <clocale>
 
 #if __APPLE__  && LIBINTL_VERSION >= 0x001201
 // for older libintl versions, setlocale is just fine
