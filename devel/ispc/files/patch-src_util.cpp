--- src/util.cpp.orig	2019-04-20 16:26:13 UTC
+++ src/util.cpp
@@ -43,7 +43,9 @@
 #include <malloc.h> // for alloca()
 #endif
 #else
+#if !defined(ISPC_IS_FREEBSD)
 #include <alloca.h>
+#endif
 #include <unistd.h>
 #endif
 #include <stdio.h>
