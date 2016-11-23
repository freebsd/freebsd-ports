--- include/osmium/util/endian.hpp.orig	2016-11-20 16:25:23 UTC
+++ include/osmium/util/endian.hpp
@@ -35,7 +35,9 @@ DEALINGS IN THE SOFTWARE.
 
 // Windows is only available for little endian architectures
 // http://stackoverflow.com/questions/6449468/can-i-safely-assume-that-windows-installations-will-always-be-little-endian
-#if !defined(_WIN32) && !defined(__APPLE__)
+#if defined(__FreeBSD__)
+# include <sys/endian.h>
+#elif !defined(_WIN32) && !defined(__APPLE__)
 # include <endian.h>
 #else
 # define __LITTLE_ENDIAN 1234
