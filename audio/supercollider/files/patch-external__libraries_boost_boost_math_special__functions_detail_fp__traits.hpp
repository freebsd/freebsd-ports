--- external_libraries/boost/boost/math/special_functions/detail/fp_traits.hpp.orig	2020-04-01 20:16:40 UTC
+++ external_libraries/boost/boost/math/special_functions/detail/fp_traits.hpp
@@ -24,7 +24,7 @@ With these techniques, the code could be simplified.
 
 #include <boost/assert.hpp>
 #include <boost/cstdint.hpp>
-#include <boost/detail/endian.hpp>
+#include <boost/predef.hpp>
 #include <boost/static_assert.hpp>
 #include <boost/type_traits/is_floating_point.hpp>
 
