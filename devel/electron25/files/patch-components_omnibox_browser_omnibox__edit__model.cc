--- components/omnibox/browser/omnibox_edit_model.cc.orig	2023-05-25 00:41:50 UTC
+++ components/omnibox/browser/omnibox_edit_model.cc
@@ -23,6 +23,7 @@
 #include "base/trace_event/trace_event.h"
 #include "base/trace_event/typed_macros.h"
 #include "build/build_config.h"
+#include "build/branding_buildflags.h"
 #include "components/bookmarks/browser/bookmark_model.h"
 #include "components/dom_distiller/core/url_constants.h"
 #include "components/dom_distiller/core/url_utils.h"
