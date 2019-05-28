--- electron/chromium_src/chrome/renderer/spellchecker/spellcheck_worditerator.cc.orig	2019-03-16 13:10:56 UTC
+++ electron/chromium_src/chrome/renderer/spellchecker/spellcheck_worditerator.cc
@@ -16,10 +16,10 @@
 #include "base/macros.h"
 #include "base/strings/stringprintf.h"
 #include "base/strings/utf_string_conversions.h"
-#include "third_party/icu/source/common/unicode/normlzr.h"
-#include "third_party/icu/source/common/unicode/schriter.h"
-#include "third_party/icu/source/common/unicode/uscript.h"
-#include "third_party/icu/source/i18n/unicode/ulocdata.h"
+#include "unicode/normlzr.h"
+#include "unicode/schriter.h"
+#include "unicode/uscript.h"
+#include "unicode/ulocdata.h"
 
 // SpellcheckCharAttribute implementation:
 
