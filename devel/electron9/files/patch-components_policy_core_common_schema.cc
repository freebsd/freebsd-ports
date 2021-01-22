--- components/policy/core/common/schema.cc.orig	2020-05-26 08:03:21 UTC
+++ components/policy/core/common/schema.cc
@@ -23,7 +23,11 @@
 #include "base/strings/stringprintf.h"
 #include "components/policy/core/common/json_schema_constants.h"
 #include "components/policy/core/common/schema_internal.h"
+#if defined(OS_FREEBSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace schema = json_schema_constants;
 
