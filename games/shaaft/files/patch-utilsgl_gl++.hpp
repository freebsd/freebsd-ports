--- utilsgl/gl++.hpp.orig	2004-01-01 04:32:28 UTC
+++ utilsgl/gl++.hpp
@@ -27,12 +27,6 @@
 # if defined(_WIN64)
 	typedef __int64 GLintptrARB;
 	typedef __int64 GLsizeiptrARB;
-# elif defined(__ia64__) || defined(__x86_64__)
-	typedef long int GLintptrARB;
-	typedef long int GLsizeiptrARB;
-# else
-	typedef int GLintptrARB;
-	typedef int GLsizeiptrARB;
 # endif
 #endif
 
