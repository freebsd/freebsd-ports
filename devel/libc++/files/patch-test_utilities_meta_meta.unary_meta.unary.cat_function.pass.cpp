--- test/utilities/meta/meta.unary/meta.unary.cat/function.pass.cpp.orig	2013-10-05 21:21:17 UTC
+++ test/utilities/meta/meta.unary/meta.unary.cat/function.pass.cpp
@@ -14,7 +14,7 @@
 #include <type_traits>
 
 template <class T>
-void test_function_imp()
+void test()
 {
     static_assert(!std::is_void<T>::value, "");
 #if _LIBCPP_STD_VER > 11
@@ -34,19 +34,34 @@ void test_function_imp()
     static_assert( std::is_function<T>::value, "");
 }
 
-template <class T>
-void test_function()
-{
-    test_function_imp<T>();
-    test_function_imp<const T>();
-    test_function_imp<volatile T>();
-    test_function_imp<const volatile T>();
-}
+// Since we can't actually add the const volatile and ref qualifiers once
+// later let's use a macro to do it.
+#define TEST_REGULAR(...)                 \
+    test<__VA_ARGS__>();                  \
+    test<__VA_ARGS__ const>();            \
+    test<__VA_ARGS__ volatile>();         \
+    test<__VA_ARGS__ cons volatile>()
+
+#define TEST_REF_QUALIFIED(...)           \
+    test<__VA_ARGS__ &>();                \
+    test<__VA_ARGS__ const &>();          \
+    test<__VA_ARGS__ volatile &>();       \
+    test<__VA_ARGS__ const volatile &>(); \
+    test<__VA_ARGS__ &&>();               \
+    test<__VA_ARGS__ const &&>();         \
+    test<__VA_ARGS__ volatile &&>();      \
+    test<__VA_ARGS__ const volatile &&>()
 
 int main()
 {
-    test_function<void ()>();
-    test_function<void (int)>();
-    test_function<int (double)>();
-    test_function<int (double, char)>();
+    TEST_REGULAR( void () );
+    TEST_REGULAR( void (int) );
+    TEST_REGULAR( int (double) );
+    TEST_REGULAR( int (double, char) );
+#if __cplusplus >= 201103L
+    TEST_REF_QUALIFIED( void () );
+    TEST_REF_QUALIFIED( void (int) );
+    TEST_REF_QUALIFIED( int (double) );
+    TEST_REF_QUALIFIED( int (double, char) );
+#endif
 }
