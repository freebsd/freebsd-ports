--- src/mutex.cpp	2010-10-31 16:56:23.000000000 -0700
+++ src/mutex.cpp	2012-08-12 20:34:58.000000000 -0700
@@ -50,6 +50,8 @@
 using namespace __gnu_cxx;
 #endif
 
+using namespace std;
+
 #ifdef  CCXX_NAMESPACES
 namespace ost {
 using namespace std;
