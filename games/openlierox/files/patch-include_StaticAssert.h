Use static_assert provided by the compiler to avoid redefining it and breaking
headers which use the official version.
--- include/StaticAssert.h.orig	2009-10-11 20:53:01 UTC
+++ include/StaticAssert.h
@@ -10,11 +10,5 @@
 #ifndef __OLX__STATICASSERT_H__
 #define __OLX__STATICASSERT_H__
 
-template <bool b> class static_assert_failure;
-template <> class static_assert_failure<true>  { char foo; };
-template <int s> class static_assert_test{};
-
-#define static_assert(X, desc)  \
-	typedef static_assert_test< (int)sizeof(static_assert_failure< (bool)(X) >) > static_assert_typedef_##desc;
 
 #endif
