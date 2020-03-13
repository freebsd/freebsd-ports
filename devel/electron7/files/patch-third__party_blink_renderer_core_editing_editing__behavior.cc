--- third_party/blink/renderer/core/editing/editing_behavior.cc.orig	2019-12-12 12:40:05 UTC
+++ third_party/blink/renderer/core/editing/editing_behavior.cc
@@ -270,7 +270,7 @@ bool EditingBehavior::ShouldInsertCharacter(const Keyb
   // unexpected behaviour
   if (ch < ' ')
     return false;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // According to XKB map no keyboard combinations with ctrl key are mapped to
   // printable characters, however we need the filter as the DomKey/text could
   // contain printable characters.
