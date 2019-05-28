--- electron/chromium_src/chrome/renderer/spellchecker/spellcheck_worditerator.h.orig	2019-03-16 13:11:46 UTC
+++ electron/chromium_src/chrome/renderer/spellchecker/spellcheck_worditerator.h
@@ -16,7 +16,7 @@
 
 #include "base/macros.h"
 #include "base/strings/string16.h"
-#include "third_party/icu/source/common/unicode/uscript.h"
+#include "unicode/uscript.h"
 
 namespace base {
 namespace i18n {
