--- client.h.orig	Wed Sep  3 19:05:06 2003
+++ client.h	Wed Sep  3 19:05:21 2003
@@ -45,6 +45,7 @@
 typedef long ssize_t;
 #endif
 #include <vector>
+using namespace std;
 
 class store_query {
 public:
