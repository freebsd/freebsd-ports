--- include/liblas12/laspoint.hpp.orig	2009-10-02 17:48:41 UTC
+++ include/liblas12/laspoint.hpp
@@ -42,10 +42,10 @@
 #ifndef LIBLAS_LASPOINT_HPP_INCLUDED
 #define LIBLAS_LASPOINT_HPP_INCLUDED
 
-#include <liblas/cstdint.hpp>
-#include <liblas/detail/fwd.hpp>
-#include <liblas/detail/utility.hpp>
-#include <liblas/lascolor.hpp>
+#include <liblas12/cstdint.hpp>
+#include <liblas12/detail/fwd.hpp>
+#include <liblas12/detail/utility.hpp>
+#include <liblas12/lascolor.hpp>
 // std
 #include <stdexcept> // std::out_of_range
 #include <cstdlib> // std::size_t
