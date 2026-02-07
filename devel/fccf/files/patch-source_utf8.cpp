--- source/utf8.cpp.orig	2022-04-29 07:01:48 UTC
+++ source/utf8.cpp
@@ -19,7 +19,9 @@
 #if _WIN32
 #  include <malloc.h>
 #else
+#ifndef __FreeBSD__
 #  include <alloca.h>
+#endif
 #endif
 
 #include <utf8.h>
