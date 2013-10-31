--- ImathTest/testShear.cpp.orig	2013-06-18 21:51:38.000000000 +0200
+++ ImathTest/testShear.cpp	2013-10-04 20:16:08.000000000 +0200
@@ -54,7 +54,6 @@
 
     const float         epsilon = IMATH_INTERNAL_NAMESPACE::limits< float >::epsilon();
 
-    float    	        array[6] = { 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F };
     IMATH_INTERNAL_NAMESPACE::Shear6f    	testConstructor1;
     IMATH_INTERNAL_NAMESPACE::Shear6f    	testConstructor2( testConstructor1 );
 
