- workaround for https://gitlab.com/mattbas/glaxnimate/-/issues/486

--- src/gui/emoji/emoji_set_dialog.cpp.orig	2022-04-19 03:42:34 UTC
+++ src/gui/emoji/emoji_set_dialog.cpp
@@ -16,6 +16,8 @@
 #include "glaxnimate_app.hpp"
 #include "emoji_dialog.hpp"
 
+#include <array>
+
 class glaxnimate::emoji::EmojiSetDialog::Private
 {
 public:
