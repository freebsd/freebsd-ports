--- lib/Alembic/Util/Murmur3.cpp.orig	2015-01-15 18:28:49 UTC
+++ lib/Alembic/Util/Murmur3.cpp
@@ -41,6 +41,8 @@
 
 #ifdef __APPLE__
 #include <machine/endian.h>
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
 #elif !defined(_MSC_VER)
 #include <endian.h>
 #endif
