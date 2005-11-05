--- src/mutex.cpp.orig	Sat Nov  5 19:54:24 2005
+++ src/mutex.cpp	Sat Nov  5 19:59:01 2005
@@ -48,6 +48,8 @@
 using namespace __gnu_cxx;
 #endif
 
+using namespace std;
+
 #ifdef	CCXX_NAMESPACES
 namespace ost {
 #endif
