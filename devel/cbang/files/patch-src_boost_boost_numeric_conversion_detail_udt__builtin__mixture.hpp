--- src/boost/boost/numeric/conversion/detail/udt_builtin_mixture.hpp.orig	2023-03-09 16:36:47 UTC
+++ src/boost/boost/numeric/conversion/detail/udt_builtin_mixture.hpp
@@ -15,15 +15,15 @@
 #include "boost/numeric/conversion/udt_builtin_mixture_enum.hpp"
 #include "boost/numeric/conversion/detail/meta.hpp"
 
-#include "boost/mpl/integral_c.hpp"
+#include "boost/type_traits/integral_constant.hpp"
 
 namespace boost { namespace numeric { namespace convdetail
 {
   // Integral Constants for 'UdtMixture'
-  typedef mpl::integral_c<udt_builtin_mixture_enum, builtin_to_builtin> builtin2builtin_c ;
-  typedef mpl::integral_c<udt_builtin_mixture_enum, builtin_to_udt>     builtin2udt_c ;
-  typedef mpl::integral_c<udt_builtin_mixture_enum, udt_to_builtin>     udt2builtin_c ;
-  typedef mpl::integral_c<udt_builtin_mixture_enum, udt_to_udt>         udt2udt_c ;
+  typedef boost::integral_constant<udt_builtin_mixture_enum, builtin_to_builtin> builtin2builtin_c ;
+  typedef boost::integral_constant<udt_builtin_mixture_enum, builtin_to_udt>     builtin2udt_c ;
+  typedef boost::integral_constant<udt_builtin_mixture_enum, udt_to_builtin>     udt2builtin_c ;
+  typedef boost::integral_constant<udt_builtin_mixture_enum, udt_to_udt>         udt2udt_c ;
 
   // Metafunction:
   //
