--- utgcns/libboost/boost/smart_ptr/detail/shared_count.hpp.orig	2021-12-18 13:01:24 UTC
+++ utgcns/libboost/boost/smart_ptr/detail/shared_count.hpp
@@ -25,6 +25,7 @@
 #include <boost/config.hpp>
 #include <boost/checked_delete.hpp>
 #include <boost/throw_exception.hpp>
+#include <boost/detail/sp_typeinfo.hpp>
 #include <boost/smart_ptr/bad_weak_ptr.hpp>
 #include <boost/smart_ptr/detail/sp_counted_base.hpp>
 #include <boost/smart_ptr/detail/sp_counted_impl.hpp>
