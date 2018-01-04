--- ImathTest/testShear.cpp.orig	2017-11-17 23:00:23 UTC
+++ ImathTest/testShear.cpp
@@ -54,7 +54,6 @@ testShear ()
 
     const float         epsilon = IMATH_INTERNAL_NAMESPACE::limits< float >::epsilon();
 
-    float    	        array[6] = { 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F };
     IMATH_INTERNAL_NAMESPACE::Shear6f    	testConstructor1;
     IMATH_INTERNAL_NAMESPACE::Shear6f    	testConstructor2( testConstructor1 );
 
