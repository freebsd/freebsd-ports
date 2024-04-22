--- third_party/blink/renderer/core/layout/ng/physical_fragment_rare_data.h.orig	2023-10-19 19:58:32 UTC
+++ third_party/blink/renderer/core/layout/ng/physical_fragment_rare_data.h
@@ -5,6 +5,7 @@
 #ifndef THIRD_PARTY_BLINK_RENDERER_CORE_LAYOUT_NG_PHYSICAL_FRAGMENT_RARE_DATA_H_
 #define THIRD_PARTY_BLINK_RENDERER_CORE_LAYOUT_NG_PHYSICAL_FRAGMENT_RARE_DATA_H_
 
+#include <bit>
 #include <climits>
 
 #include "third_party/blink/renderer/core/layout/geometry/logical_rect.h"
