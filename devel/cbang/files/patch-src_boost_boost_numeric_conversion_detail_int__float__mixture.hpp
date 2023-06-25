--- src/boost/boost/numeric/conversion/detail/int_float_mixture.hpp.orig	2023-03-09 16:36:47 UTC
+++ src/boost/boost/numeric/conversion/detail/int_float_mixture.hpp
@@ -16,15 +16,15 @@
 #include "boost/numeric/conversion/int_float_mixture_enum.hpp"
 #include "boost/numeric/conversion/detail/meta.hpp"
 
-#include "boost/mpl/integral_c.hpp"
+#include "boost/type_traits/integral_constant.hpp"
 
 namespace boost { namespace numeric { namespace convdetail
 {
   // Integral Constants for 'IntFloatMixture'
-  typedef mpl::integral_c<int_float_mixture_enum, integral_to_integral> int2int_c ;
-  typedef mpl::integral_c<int_float_mixture_enum, integral_to_float>    int2float_c ;
-  typedef mpl::integral_c<int_float_mixture_enum, float_to_integral>    float2int_c ;
-  typedef mpl::integral_c<int_float_mixture_enum, float_to_float>       float2float_c ;
+  typedef boost::integral_constant<int_float_mixture_enum, integral_to_integral> int2int_c ;
+  typedef boost::integral_constant<int_float_mixture_enum, integral_to_float>    int2float_c ;
+  typedef boost::integral_constant<int_float_mixture_enum, float_to_integral>    float2int_c ;
+  typedef boost::integral_constant<int_float_mixture_enum, float_to_float>       float2float_c ;
 
   // Metafunction:
   //
