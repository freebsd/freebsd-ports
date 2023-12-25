Obtained from:	https://github.com/fcitx/mozc/commit/131f6bf4ea9d1f49200f7ccd149fd30eae89ee97

--- src/unix/fcitx/eim.cc.orig	2020-08-14 17:09:18 UTC
+++ src/unix/fcitx/eim.cc
@@ -33,6 +33,10 @@
 #include <fcitx/module.h>
 #include <fcitx/keys.h>
 #include <fcitx-config/xdg.h>
+
+// Resolve macro naming conflict with absl.
+#undef InvokeFunction
+
 #include "fcitx_mozc.h"
 #include "mozc_connection.h"
 #include "mozc_response_parser.h"
