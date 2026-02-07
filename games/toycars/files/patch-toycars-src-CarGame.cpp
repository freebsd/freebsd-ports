--- toycars/src/CarGame.cpp.orig	2009-03-28 16:37:48.000000000 +0300
+++ toycars/src/CarGame.cpp	2013-09-14 07:36:19.958228083 +0400
@@ -48,13 +48,6 @@
 	return NULL;
 }
 #endif
-#ifndef drand48
-const double kInvRandomRange = 1.0 / RAND_MAX;
-double drand48()
-{
-	return random() * kInvRandomRange;
-}
-#endif
 
 #ifndef INFINITY
 #define INFINITY 1e20
