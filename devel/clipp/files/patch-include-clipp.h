--- include/clipp.h.orig	2023-09-19 20:16:06 UTC
+++ include/clipp.h
@@ -160,7 +160,11 @@ constexpr auto
 check_is_callable(int) -> decltype(
     std::declval<Fn>()(std::declval<Args>()...),
     std::integral_constant<bool,
+#if __cplusplus >= 201703L
+        std::is_same<Ret,typename std::invoke_result_t<Fn, Args...>>::value>{} );
+#else
         std::is_same<Ret,typename std::result_of<Fn(Args...)>::type>::value>{} );
+#endif
 
 template<class,class,class...>
 constexpr auto
@@ -171,7 +175,11 @@ constexpr auto
 check_is_callable_without_arg(int) -> decltype(
     std::declval<Fn>()(),
     std::integral_constant<bool,
+#if __cplusplus >= 201703L
+        std::is_same<Ret,typename std::invoke_result_t<Fn>>::value>{} );
+#else
         std::is_same<Ret,typename std::result_of<Fn()>::type>::value>{} );
+#endif
 
 template<class,class>
 constexpr auto
