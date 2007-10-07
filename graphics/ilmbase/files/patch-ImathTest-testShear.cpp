--- ImathTest/testShear.cpp.orig	2006-12-09 06:59:38.000000000 +0900
+++ ImathTest/testShear.cpp	2007-10-07 23:24:27.000000000 +0900
@@ -54,7 +54,6 @@
 
     const float         epsilon = Imath::limits< float >::epsilon();
 
-    float    	        array[6] = { 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F };
     Imath::Shear6f    	testConstructor1;
     Imath::Shear6f    	testConstructor2( testConstructor1 );
 
