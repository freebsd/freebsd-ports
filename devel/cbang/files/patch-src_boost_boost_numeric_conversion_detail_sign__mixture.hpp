--- src/boost/boost/numeric/conversion/detail/sign_mixture.hpp.orig	2023-03-09 16:36:47 UTC
+++ src/boost/boost/numeric/conversion/detail/sign_mixture.hpp
@@ -16,15 +16,15 @@
 #include "boost/numeric/conversion/sign_mixture_enum.hpp"
 #include "boost/numeric/conversion/detail/meta.hpp"
 
-#include "boost/mpl/integral_c.hpp"
+#include "boost/type_traits/integral_constant.hpp"
 
 namespace boost { namespace numeric { namespace convdetail
 {
   // Integral Constants for 'SignMixture'
-  typedef mpl::integral_c<sign_mixture_enum, unsigned_to_unsigned> unsig2unsig_c ;
-  typedef mpl::integral_c<sign_mixture_enum, signed_to_signed>     sig2sig_c ;
-  typedef mpl::integral_c<sign_mixture_enum, signed_to_unsigned>   sig2unsig_c ;
-  typedef mpl::integral_c<sign_mixture_enum, unsigned_to_signed>   unsig2sig_c ;
+  typedef boost::integral_constant<sign_mixture_enum, unsigned_to_unsigned> unsig2unsig_c ;
+  typedef boost::integral_constant<sign_mixture_enum, signed_to_signed>     sig2sig_c ;
+  typedef boost::integral_constant<sign_mixture_enum, signed_to_unsigned>   sig2unsig_c ;
+  typedef boost::integral_constant<sign_mixture_enum, unsigned_to_signed>   unsig2sig_c ;
 
   // Metafunction:
   //
