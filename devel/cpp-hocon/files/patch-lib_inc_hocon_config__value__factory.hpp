--- lib/inc/hocon/config_value_factory.hpp.orig	2016-09-23 20:45:10 UTC
+++ lib/inc/hocon/config_value_factory.hpp
@@ -2,9 +2,10 @@
 
 #include "types.hpp"
 #include "export.h"
+#include <string>
 
 namespace hocon {
-    class LIBCPP_HOCON_EXPORT config_value_factory {
+    class CPP_HOCON_EXPORT config_value_factory {
          public:
          /**
           * Creates a {@link ConfigValue} from a plain value, which may be
