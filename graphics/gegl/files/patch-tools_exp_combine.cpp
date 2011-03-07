--- tools/exp_combine.cpp.orig	2011-03-02 09:30:13.000000000 +0100
+++ tools/exp_combine.cpp	2011-03-02 09:27:16.000000000 +0100
@@ -6,6 +6,11 @@
 #include <cerrno>
 #include <cmath>
 
+#include <sys/param.h>
+#if __FreeBSD_version <= 704100 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2f(x) (logf(x) / logf(2))
+#endif
+
 #include <iostream>
 
 #include <exiv2/image.hpp>
