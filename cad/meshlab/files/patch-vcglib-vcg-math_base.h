--- ../../vcglib/vcg/math/base.h.orig	2012-04-05 11:04:15.000000000 +0200
+++ ../../vcglib/vcg/math/base.h	2013-10-31 11:09:34.000000000 +0100
@@ -94,7 +94,9 @@
 /// static_assert: implemented as a macro for "assert", but it is separated for clarity.
 /// Should be used for checking integrity constraints that can be tested at complile time,
 /// as the ones involving templated constants in templated classes.
+#ifndef static_assert
 #define static_assert assert
+#endif
 
   #ifdef __BORLANDC__
     float sqrtf (float v) {return sqrt(v);}
