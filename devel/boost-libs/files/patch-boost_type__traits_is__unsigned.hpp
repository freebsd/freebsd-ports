--- boost/type_traits/is_unsigned.hpp.orig	2025-08-06 18:49:14 UTC
+++ boost/type_traits/is_unsigned.hpp
@@ -13,6 +13,7 @@
 #include <boost/type_traits/is_integral.hpp>
 #include <boost/type_traits/is_enum.hpp>
 #include <boost/type_traits/remove_cv.hpp>
+#include <boost/core/underlying_type.hpp>
 
 #include <climits>
 
@@ -26,6 +27,18 @@ namespace detail{
 
 namespace detail{
 
+template <class no_cv_t, bool is_enum>
+struct is_unsigned_values_underlying_type
+{
+   typedef no_cv_t underlying_type;
+};
+
+template <class no_cv_t>
+struct is_unsigned_values_underlying_type<no_cv_t, true>
+{
+   typedef typename ::boost::underlying_type<no_cv_t>::type underlying_type;
+};
+
 template <class T>
 struct is_unsigned_values
 {
@@ -35,8 +48,10 @@ struct is_unsigned_values
    // the correct answer.
    //
    typedef typename remove_cv<T>::type no_cv_t;
-   static const no_cv_t minus_one = (static_cast<no_cv_t>(-1));
-   static const no_cv_t zero = (static_cast<no_cv_t>(0));
+   typedef typename is_unsigned_values_underlying_type<no_cv_t, ::boost::is_enum<T>::value>::underlying_type underlying_type;
+
+   static const underlying_type minus_one = (static_cast<underlying_type>(-1));
+   static const underlying_type zero = (static_cast<underlying_type>(0));
 };
 
 template <class T>
