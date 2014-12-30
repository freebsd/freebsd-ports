diff --git src/cguittfont/irrUString.h src/cguittfont/irrUString.h
index 32efaa6..c175c79 100644
--- src/cguittfont/irrUString.h
+++ src/cguittfont/irrUString.h
@@ -47,6 +47,8 @@
 #define __BIG_ENDIAN 1
 #elif __MACH__
 #include <machine/endian.h>
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
 #else
 #include <endian.h>
 #endif
