--- boost/type_traits/is_signed.hpp.orig	2025-08-06 18:49:14 UTC
+++ boost/type_traits/is_signed.hpp
@@ -13,6 +13,7 @@
 #include <boost/type_traits/is_integral.hpp>
 #include <boost/type_traits/remove_cv.hpp>
 #include <boost/type_traits/is_enum.hpp>
+#include <boost/core/underlying_type.hpp>
 #include <climits>
 
 namespace boost {
@@ -25,6 +26,18 @@ namespace detail{
 
 namespace detail{
 
+template <class no_cv_t, bool is_enum>
+struct is_signed_values_underlying_type
+{
+   typedef no_cv_t underlying_type;
+};
+
+template <class no_cv_t>
+struct is_signed_values_underlying_type<no_cv_t, true>
+{
+   typedef typename ::boost::underlying_type<no_cv_t>::type underlying_type;
+};
+
 template <class T>
 struct is_signed_values
 {
@@ -34,14 +47,15 @@ struct is_signed_values
    // the correct answer.
    //
    typedef typename remove_cv<T>::type no_cv_t;
-   static const no_cv_t minus_one = (static_cast<no_cv_t>(-1));
-   static const no_cv_t zero = (static_cast<no_cv_t>(0));
+   typedef typename is_signed_values_underlying_type<no_cv_t, ::boost::is_enum<T>::value>::underlying_type underlying_type;
+
+   static const underlying_type minus_one = (static_cast<underlying_type>(-1));
+   static const underlying_type zero = (static_cast<underlying_type>(0));
 };
 
 template <class T>
 struct is_signed_helper
 {
-   typedef typename remove_cv<T>::type no_cv_t;
    BOOST_STATIC_CONSTANT(bool, value = (!(::boost::detail::is_signed_values<T>::minus_one  > boost::detail::is_signed_values<T>::zero)));
 };
 
