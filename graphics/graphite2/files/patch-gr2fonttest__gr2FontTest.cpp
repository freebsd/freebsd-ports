--- ./gr2fonttest/gr2FontTest.cpp.orig	2011-09-22 17:30:02.000000000 +0200
+++ ./gr2fonttest/gr2FontTest.cpp	2012-01-22 10:24:33.468384204 +0100
@@ -176,7 +176,7 @@
 #ifdef WIN32
     const char * pText = reinterpret_cast<char*>(pIn);
 #else
-    char * pText = reinterpret_cast<char*>(pIn);
+    const char * pText = reinterpret_cast<char*>(pIn);
 #endif
     // It seems to be necessary to include the trailing null to prevent
     // stray characters appearing with utf16
