--- sipp.hpp.orig	Tue Feb  1 15:12:35 2005
+++ sipp.hpp	Tue Feb  1 15:12:49 2005
@@ -268,7 +268,7 @@
 void pollset_remove(int idx);
 int pollset_add(call * p_call, int socket);
 
-#if defined (__hpux) || defined (__alpha)
+#if defined (__hpux)
 #define sipp_socklen_t  int
 #else
 #define sipp_socklen_t  socklen_t
