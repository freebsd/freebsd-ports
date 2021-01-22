--- components/url_matcher/regex_set_matcher.cc.orig	2020-05-26 07:48:21 UTC
+++ components/url_matcher/regex_set_matcher.cc
@@ -12,8 +12,13 @@
 #include "base/logging.h"
 #include "base/strings/string_util.h"
 #include "components/url_matcher/substring_set_matcher.h"
+#if defined(OS_BSD)
+#include <re2/filtered_re2.h>
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/filtered_re2.h"
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace url_matcher {
 
