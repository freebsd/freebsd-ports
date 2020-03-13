--- components/keyed_service/core/dependency_graph_unittest.cc.orig	2019-12-12 12:39:30 UTC
+++ components/keyed_service/core/dependency_graph_unittest.cc
@@ -9,7 +9,11 @@
 #include "components/keyed_service/core/dependency_graph.h"
 #include "components/keyed_service/core/dependency_node.h"
 #include "testing/gtest/include/gtest/gtest.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace {
 
