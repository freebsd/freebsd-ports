--- ./common/unordered_defs.h.orig	2013-10-29 15:57:51.000000000 +0100
+++ ./common/unordered_defs.h	2013-10-29 15:57:51.000000000 +0100
@@ -0,0 +1,19 @@
+
+#include "autoconfig.h"
+
+#ifdef  HAVE_CXX0X_UNORDERED
+#  include <unordered_map>
+#  include <unordered_set>
+#  define STD_UNORDERED_MAP std::unordered_map
+#  define STD_UNORDERED_SET std::unordered_set
+#elif defined(HAVE_TR1_UNORDERED)
+#  include <tr1/unordered_map>
+#  include <tr1/unordered_set>
+#  define STD_UNORDERED_MAP std::tr1::unordered_map
+#  define STD_UNORDERED_SET std::tr1::unordered_set
+#else
+#  include <map>
+#  include <set>
+#  define STD_UNORDERED_MAP std::map
+#  define STD_UNORDERED_SET std::set
+#endif
