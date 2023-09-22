--- src/mutex.cpp.orig	2023-05-01 18:05:51 UTC
+++ src/mutex.cpp
@@ -4,6 +4,7 @@
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt) */
 
 EMILUA_GPERF_DECLS_BEGIN(includes)
+#define FMT_HEADER_ONLY
 #include <fmt/format.h>
 
 #include <emilua/mutex.hpp>
