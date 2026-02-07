--- source/glest_game/ai/ai_rule.cpp.orig	2019-12-21 13:33:29 UTC
+++ source/glest_game/ai/ai_rule.cpp
@@ -16,6 +16,7 @@
 #include "ai_interface.h"
 #include "unit.h"
 #include "leak_dumper.h"
+#include <climits>
 
 using Shared::Graphics::Vec2i;
 
