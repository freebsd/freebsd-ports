--- components/plugins/renderer/plugin_placeholder.cc.orig	2019-12-12 12:39:31 UTC
+++ components/plugins/renderer/plugin_placeholder.cc
@@ -17,7 +17,11 @@
 #include "third_party/blink/public/web/web_plugin_container.h"
 #include "third_party/blink/public/web/web_script_source.h"
 #include "third_party/blink/public/web/web_serialized_script_value.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif // defined(OS_BSD)
 
 namespace plugins {
 
