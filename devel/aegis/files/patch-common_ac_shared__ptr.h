--- common/ac/shared_ptr.h.orig	2012-12-04 02:03:33 UTC
+++ common/ac/shared_ptr.h
@@ -21,23 +21,6 @@
 #define COMMON_AC_SHARED_PTR_H
 
 #include <common/config.h>
-
-#ifdef HAVE_TR1_MEMORY
-
-#include <tr1/memory>
-
-#define aegis_shared_ptr std::tr1::shared_ptr
-
-#elif HAVE_BOOST_SHARED_PTR_HPP
-
-#include <boost/shared_ptr.hpp>
-
-#define aegis_shared_ptr boost::shared_ptr
-
-#else
-
 #include <common/ac/shared_ptr/aegis.h>
 
-#endif
-
 #endif // COMMON_AC_SHARED_PTR_H
