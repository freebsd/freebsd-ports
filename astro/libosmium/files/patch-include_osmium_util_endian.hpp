--- include/osmium/util/endian.hpp.orig	2017-01-14 10:50:34 UTC
+++ include/osmium/util/endian.hpp
@@ -35,7 +35,7 @@ DEALINGS IN THE SOFTWARE.
 
 // Windows is only available for little endian architectures
 // http://stackoverflow.com/questions/6449468/can-i-safely-assume-that-windows-installations-will-always-be-little-endian
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 # include <sys/endian.h>
 #elif !defined(_WIN32) && !defined(__APPLE__)
 # include <endian.h>
