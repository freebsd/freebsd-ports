--- boost/dll/detail/posix/program_location_impl.hpp.orig	2025-04-03 11:37:24 UTC
+++ boost/dll/detail/posix/program_location_impl.hpp
@@ -83,7 +84,7 @@ namespace boost { namespace dll { namespace detail {
 
         std::string p;
         p.resize(size);
-        if (sysctl(mib, 4, p.data(), &size, nullptr, 0) != 0) {
+        if (sysctl(mib, 4, &p[0], &size, nullptr, 0) != 0) {
             ec = std::make_error_code(
                 static_cast<std::errc>(errno)
             );
