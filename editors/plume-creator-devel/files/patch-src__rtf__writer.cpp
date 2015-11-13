--- src/rtf/writer.cpp.orig	2015-05-10 16:46:22 UTC
+++ src/rtf/writer.cpp
@@ -30,6 +30,10 @@
 #include <windows.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <locale.h>
+#endif
+
 //-----------------------------------------------------------------------------
 
 namespace
